#include "StdAfx.h"
#include "NormalizedSizeDPI.h"

namespace DuiLib {
	// 归一化值放大1000倍变成整数
	static const int kNormalizedMultiple = 1000;
	int CNormalizedSizeDPI::Scale(int iValue) {

		auto new_value = iValue;
		if (m_paintWindowInitSize.cx > 0) {
			new_value = iValue * m_paintWindowSize.cx / (double)m_paintWindowInitSize.cx;
		}
		return CDPI::Scale(new_value);
	}

	int CNormalizedSizeDPI::ScaleBack(int iValue) {

		auto new_value = iValue;
		if (m_paintWindowInitSize.cx > 0) {
			new_value = iValue * m_paintWindowSize.cx / (double)m_paintWindowInitSize.cx;
		}
		return CDPI::ScaleBack(new_value);
	}

	
}