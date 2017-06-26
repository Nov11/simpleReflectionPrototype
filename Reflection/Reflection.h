#pragma once
#include <string>
#include <unordered_map>

#define REFLECTABLE(className, createInstanceFunctionPtr) \
Reflection::RegHelper r##className(#className, createInstanceFunctionPtr)

namespace Reflection {
	using newInstance = void* (*)();
	class Factory {
	public:
		void* createInstance(std::string className) {
			auto iter = hash_.find(className);
			if (iter == hash_.end()) { return nullptr; }
			else { return iter->second(); }
		}

		void registerClass(std::string className, newInstance n) {
			auto iter = hash_.find(className);
			if (iter == hash_.end()) { hash_[className] = n; }
		}

		static Factory& getFactory() {
			static Factory f;
			return f;
		}
	private:
		std::unordered_map<std::string, newInstance> hash_;
	};

	//class Reflectable {
	//public:
	//	//virtual void* createInstance() = 0;
	//	virtual ~Reflectable() {}
	//};

	class RegHelper {
	public:
		RegHelper(std::string className, newInstance n) {
			Factory::getFactory().registerClass(className, n);
		}
	};
}