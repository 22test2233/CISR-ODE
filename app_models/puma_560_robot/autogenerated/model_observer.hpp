
// *** Warning:
// *** auto-generated file and subjected to be overwritten

// path: ./app_models/puma_560_robot/autogenerated/model_observer.hpp

#pragma once

using namespace arma;

void Model::observer(
	const state_type 			&x ,
	const double 				&t,
	observer_type 				&ymat,
	const intermediate_type 	&last_observed_mids,
	const time_type 			&last_observed_t,
	input_type					&u
	)
{
	intermediate_type mid;
	intermediates(u,x,mid,t,last_observed_mids,last_observed_t);

	// y0	theta_desired[0];
	// y1	theta_desired[1];
	// y2	theta_desired[2];
	// y3	theta[0];
	// y4	theta[1];
	// y5	theta[2];
	// y6	position[0];
	// y7	position[1];
	// y8	position[2];
	// y9	error;

	ymat.subvec(outputs::theta_desired_0,outputs::theta_desired_2)=mid.subvec(mids::theta_desired_0,mids::theta_desired_end);
	ymat.subvec(outputs::theta_0,outputs::theta_2)=mid.subvec(mids::theta_0,mids::theta_end);
	ymat.subvec(outputs::position_0,outputs::position_2)=mid.subvec(mids::position_0,mids::position_end);
	ymat(outputs::error)=mid(mids::error);

}
