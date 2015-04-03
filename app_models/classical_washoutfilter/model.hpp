#pragma once

#include "types.hpp"
#include "constants.hpp"

using namespace arma;

class Model
{
public:

	static void rhs(
		const state_type 			&x,
		state_type 					&x_dot,
		const time_type				&t,
		const state_type 			&last_observed_x,
		const time_type 			&last_observed_t,
		input_type					&u
		);

	static void observer(
		const state_type 			&x ,
		const double 				&t,
		observer_type 				&ymat,
		const state_type 			&last_observed_x,
		const time_type 			&last_observed_t,
		input_type					&u
		);

	static void intermediates(
		const input_type &u,
		const state_type &x,
		intermediate_type &mid,
		const time_type &t,
		const state_type &last_observed_x,
		const time_type &last_observed_t
		);

	static double input(const time_type t,input_type &u)
	{
		// u0	surge_acc
		// u1	pitch_vel

		u(inputs::surge_acc)=(t>1.0&&t<5.0?1.0:0.0);
		u(inputs::pitch_vel)=0;

		double next_sudden_change_time=-1;
		return next_sudden_change_time;
	}

protected:

	static void hp_surge(const intermediate_type &mid,const state_type &x,state_type &x_dot)
	{
		// observable form
		const double w=platform::omega_hp_x;
		const double z=platform::zeta_hp_x;
		const int x1=states::surge_hp_x1;
		const int x2=states::surge_hp_x2;
		x_dot(x1)=-w*w*x(x2)-w*w*mid(mids::surge_input_acc_ref);
		x_dot(x2)=x(x1)-2*z*w*x(x2)-2*z*w*mid(mids::surge_input_acc_ref);
	}

	static double hp_surge_out(const intermediate_type &mid,const state_type &x)
	{
		return x(states::surge_hp_x2)+mid(mids::surge_input_acc_ref);
	}

	static void lp_surge(const intermediate_type &mid,const state_type &x, state_type &x_dot)
	{
		// observable form
		const double w=platform::omega_lp_x;
		const double z=platform::zeta_lp_x;
		const int x1=states::surge_lp_x1;
		const int x2=states::surge_lp_x2;
		x_dot(x1)=-w*w*x(x2)+w*w*mid(mids::surge_input_acc_ref);
		x_dot(x2)=x(x1)-2*z*w*x(x2);
	}

	static double lp_surge_out(const state_type &x)
	{
		return x(states::surge_lp_x2);
	}

	static void hp_pitch(const intermediate_type &mid,const state_type &x, state_type &x_dot)
	{
		// observable form
		const double w=platform::omega_hp_pitch;
		const int x1=states::pitch_hp_x1;
		x_dot(x1)=-w*x(x1)-w*mid(mids::pitch_input_angle_ref);
	}

	static double hp_pitch_out(const intermediate_type &mid,const state_type &x)
	{
		return x(states::pitch_hp_x1)+mid(mids::pitch_input_angle_ref);
	}
};

#include "autogenerated/model_observer.hpp"
#include "model_mids.hpp"
#include "model_rhs.hpp"