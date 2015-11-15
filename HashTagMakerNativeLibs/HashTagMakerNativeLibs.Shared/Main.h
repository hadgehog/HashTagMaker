#pragma once
#include "MainNative.h"

namespace HashTagMakerNativeLibs{
	public ref class Main sealed{
	private:
		std::shared_ptr<MainNative> nativeMain;

	public:
		Main();
		virtual ~Main();

		void ParseInputString(Platform::String ^input);
		Platform::String ^GetHashtags();
		Platform::String ^GetBaseString();
		void ClearCurrentSentence();
	};
}
