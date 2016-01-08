
// *** Warning:
// *** auto-generated file and subjected to be overwritten

// path: ./app_models/transmission_line/autogenerated/user_template.hpp

// inputs

	// u[0]	v_in

	u(inputs::v_in)=...

// intermediates

	// m[0]	v_in
	// m[1]	v_end

	mid(mids::v_in)=...
	mid(mids::v_end)=...

// states

	// x[0:99]	q[100]
	// x[100:199]	phi[100]

	x_dot.subvec(states::q_0,states::q_end)=...
	x_dot.subvec(states::phi_0,states::phi_end)=...
