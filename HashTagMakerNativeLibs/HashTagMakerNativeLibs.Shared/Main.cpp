#include "pch.h"
#include "Main.h"

using namespace HashTagMakerNativeLibs;
using namespace Platform;

Main::Main(){
	this->nativeMain = std::make_shared<MainNative>();
}

Main::~Main(){
	this->nativeMain = nullptr;
}

void Main::ParseInputString(String ^input) {
	this->nativeMain->ParseInputString(input->Data());
}

Platform::String ^Main::GetHashtags() {
	String ^result = ref new String(this->nativeMain->GetHashtags().c_str());
	return result;
}

Platform::String ^Main::GetBaseString() {
	String ^result = ref new String(this->nativeMain->GetBaseString().c_str());
	return result;
}

void Main::ClearCurrentSentence() {
	this->nativeMain->ClearCurrentSentence();
}