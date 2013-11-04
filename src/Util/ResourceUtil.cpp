#include "ResourceUtil.h"

namespace Statistica{

	ResourceUtil::ResourceUtil(){
		_resourceManager = gcnew ResourceManager("Statistica.Resource", Assembly::GetExecutingAssembly());
		_cultureInfo = CultureInfo::CurrentCulture;
	}

	ResourceManager^ ResourceUtil::resourceManager::get(){
		return _resourceManager;
	}

	CultureInfo^ ResourceUtil::cultureInfo::get(){
		return _cultureInfo;
	}

	void ResourceUtil::cultureInfo::set(CultureInfo^ ci){
		_cultureInfo = ci;
	}

	ResourceUtil^ ResourceUtil::getInstance(){
		if (me == nullptr)
			me = gcnew ResourceUtil();
		return me;
	}

	String^ ResourceUtil::getString(String^ key){
		return getInstance()->_resourceManager->GetString(key, getInstance()->_cultureInfo);
	}

	String^ ResourceUtil::getString(String^ key, array<Object^>^ args){
		return String::Format(getString(key), args);
	}
}
