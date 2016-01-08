
// *** Warning:
// *** auto-generated file and subjected to be overwritten

// path: ./app_models/puma_560_robot/autogenerated/model_intermediates.hpp

#pragma once

namespace mids
{
	// m[0:2]	theta_desired[3]
	// m[3:5]	D_theta_desired[3]
	// m[6:8]	DD_theta_desired[3]
	// m[9:11]	theta[3]
	// m[12:14]	D_theta[3]
	// m[15:17]	theta_error[3]
	// m[18:20]	D_theta_error[3]
	// m[21:26]	DD_theta_controller[6]
	// m[27:32]	T[6]
	// m[33:38]	angular_vec[6]
	// m[39:41]	position[3]
	// m[42:44]	position_desired[3]
	// m[45]	error

	const uint theta_desired_0=0;
	const uint theta_desired_end=2;
	const uint D_theta_desired_0=3;
	const uint D_theta_desired_end=5;
	const uint DD_theta_desired_0=6;
	const uint DD_theta_desired_end=8;
	const uint theta_0=9;
	const uint theta_1=10;
	const uint theta_2=11;
	const uint theta_end=11;
	const uint D_theta_0=12;
	const uint D_theta_end=14;
	const uint theta_error_0=15;
	const uint theta_error_end=17;
	const uint D_theta_error_0=18;
	const uint D_theta_error_end=20;
	const uint DD_theta_controller_0=21;
	const uint DD_theta_controller_2=23;
	const uint DD_theta_controller_3=24;
	const uint DD_theta_controller_end=26;
	const uint T_0=27;
	const uint T_end=32;
	const uint angular_vec_0=33;
	const uint angular_vec_2=35;
	const uint angular_vec_3=36;
	const uint angular_vec_end=38;
	const uint position_0=39;
	const uint position_end=41;
	const uint position_desired_0=42;
	const uint position_desired_end=44;
	const uint error=45;

	// total size of mids vector
	const int intermediate_size=46;
}
