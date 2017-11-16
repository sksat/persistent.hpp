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

class persistent_base {
public:
	static bool load(double s){
		if(khpc::persistent_load(s) == -1)
			return false;
		return true;
	}
	static bool load(){ return load(0); }

	static bool save(double s){
		if(khpc::persistent_save(s) == -1)
			return false;
		return true;
	}
	static bool save(){ return save(0); }

	static void def(void *p, int size, int grpId, const char *id){
		khpc::persistent_def(p, size, grpId, id);
	}
};

template<typename T>
class persistent_wrapper : public persistent_base {
public:
	persistent_wrapper(T &var, const char *id): var(var) {
		def(var, id);
	}

	T &var;

	static void def(T &var, const char *id){
		persistent_base::def(&var, sizeof(T), 256, id);
	}
	static void def(T &var, size_t num, const char *id){
		persistent_base::def(&var, sizeof(T)*num, 256, id);
	}

};

namespace persistent {
	void load(){ persistent_base::load(); }
	void save(){ persistent_base::save(); }
}

#define perpetuate(var)	(persistent_wrapper<decltype(var)>(var, #var))

#endif
