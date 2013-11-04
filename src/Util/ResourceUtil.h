#pragma once

namespace Statistica{
	using namespace System;
	using namespace System::Resources;
	using namespace System::Reflection;
	using namespace System::Globalization;

	public ref class ResourceUtil {
	private:
		static ResourceUtil^ me;
		ResourceManager^ _resourceManager;
		CultureInfo^ _cultureInfo;

		ResourceUtil();
	public:
		property ResourceManager^ resourceManager{
			ResourceManager^ get();
		}

		property CultureInfo^ cultureInfo{
			CultureInfo^ get();
			void set(CultureInfo^ ci);
		}

		static ResourceUtil^ getInstance();
		static String^ getString(String^ key);
		static String^ getString(String^ key, array<Object^>^ args);
	};
}
