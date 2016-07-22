#pragma once
#include <spina/module.hpp>
#include <spina/messages/messages.hpp>

class InputModule : public spina::Module {
	public:
		InputModule() : spina::Module("input", "Joe Eaves"){};
		void setup();
		void tick();
	private:
		spina::messages::Message out{"input"};

};

// Init/Del functions.
extern "C" SPINA_WINEXPORT InputModule* createModule();
extern "C" SPINA_WINEXPORT void destroyModule(InputModule* module);
