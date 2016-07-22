#pragma once
#include <spina/module.hpp>
#include <spina/messages/messages.hpp>

class OutputModule : public spina::Module {
	public:
		OutputModule() : spina::Module("output", "Joe Eaves"){};
		void setup();
		void tick();
	private:
		spina::messages::Message message{"output"};

		void hookOut();

};

// Init/Del functions.
extern "C" SPINA_WINEXPORT OutputModule* createModule();
extern "C" SPINA_WINEXPORT void destroyModule(OutputModule* module);
