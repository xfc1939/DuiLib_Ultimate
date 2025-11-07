#pragma once
#include "DPI.h"
namespace DuiLib {
	class CNormalizedSizeDPI : public CDPI {
	public:
		int Scale(int iValue) override;
		int ScaleBack(int iValue) override;
		float GetNormalScale() override;
	};
}
