#ifndef PERSISTENT_HPP_
#define PERSISTENT_HPP_

// KHPCを使用する
namespace khpc {

extern "C" {
#include "khpc/khpc0.h"

void persistent_default(){
	persistent_grp(256, "p-vars.pbd", "p-vars_%x.pbd", "(local)");
	return;
}
}
}

class persistent {
public:
	static void load(){ khpc::persistent_load(0); }
	static void save(){ khpc::persistent_save(0); }

	template<typename T>
	static void def(T &t, const char *id){
		khpc::persistent_def(&t, sizeof(T), 256, id);
	}

};

#define perpetuate(var)	persistent::def(var, #var);

#endif
