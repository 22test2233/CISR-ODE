// This program renders autogenerated code for the main application

#include <string>
#include "ag-config.hpp"
#include "ag-dictionaries.hpp"


void main_model_only()
{
	std::cout<<"The name of active model is: "<<ag_config.model_name<<std::endl;
}

void main_autogenerator()
{
	std::string template_vectorindex_text=filesystem::read_file(ag_config.template_vectorindex);
	std::string template_vectorindex_output_text=filesystem::read_file(ag_config.template_vectorindex_output);
	std::string template_observer_text=filesystem::read_file(ag_config.template_observer);
	std::string template_usertemplate_text=filesystem::read_file(ag_config.template_usertemplate);
	std::string template_embed_text=filesystem::read_file(ag_config.template_embed);

	filesystem::ensure_folder(ag_config.model_autogen_folder);
	filesystem::ensure_folder(ag_config.mainapp_autogen_folder);

	// include model
	AG_Dictionary_embed dictionary_embed(ag_config.model_name);
	std::string embed_text(dictionary_embed.replace_dictionary(template_embed_text));
	filesystem::write_file(ag_config.autogen_embed,embed_text);

	// input
	AG_Dictionary_input dictionary_input;
	std::string input_text(dictionary_input.replace_dictionary(template_vectorindex_text));
	filesystem::write_file(ag_config.autogen_inputs,input_text);
	// intermediate
	AG_Dictionary_mid dictionary_intermediate;
	std::string intermediate_text(dictionary_intermediate.replace_dictionary(template_vectorindex_text));
	filesystem::write_file(ag_config.autogen_intermediates,intermediate_text);
	// outputs
	AG_Dictionary_output dictionary_outputs;
	std::string outputs_text(dictionary_outputs.replace_dictionary(template_vectorindex_output_text));
	filesystem::write_file(ag_config.autogen_outputs,outputs_text);
	// state
	AG_Dictionary_state dictionary_state;
	std::string state_text(dictionary_state.replace_dictionary(template_vectorindex_text));
	filesystem::write_file(ag_config.autogen_states,state_text);
	// observer
	AG_Dictionary_observer dictionary_observer;
	std::string observer_text(dictionary_observer.replace_dictionary(template_observer_text));
	filesystem::write_file(ag_config.autogen_observer,observer_text);
	// user template
	AG_Dictionary_usertemplate dictionary_usertemplate;
	std::string usertemplate_text(dictionary_usertemplate.replace_dictionary(template_usertemplate_text));
	filesystem::write_file(ag_config.autogen_usertemplate,usertemplate_text);

}

int main()
{
	#ifdef SHOW_MODEL_NAME_ONLY
		main_model_only();
	#else
		std::cout<<"Automatic generating code ..."<<std::endl;
		main_autogenerator();
		std::cout<<"Automatic codes are generated ..."<<std::endl;
	#endif
	return 0;
}