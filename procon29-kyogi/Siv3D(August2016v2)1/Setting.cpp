#include "Setting.h"

Setting* Setting::InsSetting = nullptr;
Setting* Setting::getSetting() {
	if (InsSetting == nullptr) {
		InsSetting = new Setting;
		InsSetting->turnFlag = true;
	}
	return InsSetting;
}