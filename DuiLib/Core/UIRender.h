#ifndef __UIRENDER_H__
#define __UIRENDER_H__

#pragma once

#ifdef USE_XIMAGE_EFFECT
class CxImage;
#endif

namespace DuiLib {
	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CRenderClip
	{
	public:
		~CRenderClip();
		RECT rcItem;
		HDC hDC;
		HRGN hRgn;
		HRGN hOldRgn;

		static void GenerateClip(HDC hDC, RECT rc, CRenderClip& clip);
		static void GenerateRoundClip(HDC hDC, RECT rc, RECT rcItem, int width, int height, CRenderClip& clip);
		static void UseOldClipBegin(HDC hDC, CRenderClip& clip);
		static void UseOldClipEnd(HDC hDC, CRenderClip& clip);
	};

	/////////////////////////////////////////////////////////////////////////////////////
	//

	class UILIB_API CRenderEngine
	{

	private:
		static Gdiplus::Rect RECT2GdiplusRect(const RECT& rc);

	public:
		// 图片处理
#ifdef USE_XIMAGE_EFFECT
		static CxImage *LoadGifImageX(STRINGorID bitmap, LPCTSTR type = NULL, DWORD mask = 0);
#endif
		static TImageInfo* LoadImage(STRINGorID bitmap, LPCTSTR type = NULL, DWORD mask = 0, HINSTANCE instance = NULL);
		static void FreeImage(TImageInfo* pImageInfo, bool bDelete = true);
		static TImageInfo* LoadImage(LPCTSTR pStrImage, LPCTSTR type = NULL, DWORD mask = 0, HINSTANCE instance = NULL);
		static TImageInfo* LoadImage(UINT nID, LPCTSTR type = NULL, DWORD mask = 0, HINSTANCE instance = NULL);

		static void DrawImage(HDC hDC, HBITMAP hBitmap, const RECT& rc, const RECT& rcPaint, const RECT& rcBmpPart, const RECT& rcCorners, bool bAlpha, UINT uFade = 255, bool hole = false, bool xtiled = false, bool ytiled = false);
                static bool DrawImageInfo(HDC hDC, CPaintManagerUI* pManager, const RECT& rcItem, const RECT& rcPaint, const TDrawInfo* pDrawInfo, HINSTANCE instance = NULL, int bkradius = 0, int cut_type = 0);
                static bool DrawImageString(HDC hDC, CPaintManagerUI* pManager, const RECT& rcItem, const RECT& rcPaint, LPCTSTR pStrImage, LPCTSTR pStrModify = NULL, HINSTANCE instance = NULL, int bkradius = 0, int cut_type = 0);

                // Gdiplus相关
                static TImageInfo* GdiplusLoadImage(STRINGorID bitmap, LPCTSTR type = NULL, DWORD mask = 0, HINSTANCE instance = NULL);
                static void GdiplusDrawImage(HDC hDC, Gdiplus::Image* image, const RECT& rc, const RECT& rcPaint, const RECT& rcBmpPart, const RECT& rcCorner, bool bAlpha, UINT uFade = 255, UINT uRotate = 0, int bkradius = 0);
                static void GdiplusDrawText(HDC hDC, CPaintManagerUI* pManager, RECT& rc, LPCTSTR pstrText, DWORD dwTextColor, int iFont, UINT uStyle);

                // 调整颜色的HSL和alpha值等效果
		// 图元绘制
		static void DrawColor(HDC hDC, const RECT& rc, DWORD color);
		// 设置顶部圆角和底部圆角值
		static void DrawColor(HDC hDC, const RECT& rc, DWORD color, const int topRadius, const int bottomRadius);
		static void DrawColor(HDC Hdc, const RECT& rcItem, const RECT& rcPaint, DWORD color, const int radius);
		static void DrawGradient(HDC hDC, const RECT& rc, DWORD dwFirst, DWORD dwSecond, bool bVertical, int nSteps);
		static void GdiplusDrawGradient(HDC hDC, const RECT& rc, DWORD dwFirst, DWORD dwSecond, bool bVertical, int radius);
		static void DrawLine(HDC hDC, const RECT& rc, int nSize, DWORD dwPenColor,int nStyle = PS_SOLID);
		static void DrawRect(HDC hDC, const RECT& rc, int nSize, DWORD dwPenColor,int nStyle = PS_SOLID);
		static void DrawRoundRect(HDC hDC, const RECT& rc, int nSize, int width, int height, DWORD dwPenColor, int nStyle = PS_SOLID);
		static void DrawRoundRectWithFill(HDC hDC, const RECT& rc, int nSize, int width, int height, DWORD dwPenColor, DWORD dwFillColor, int nStyle = PS_SOLID);

		// 绘制文本
		static void DrawText(HDC hDC, CPaintManagerUI* pManager, RECT& rc, LPCTSTR pstrText,DWORD dwTextColor, int iFont, UINT uStyle, DWORD dwTextBKColor);
		static void DrawText(HDC hDC, CPaintManagerUI* pManager, RECT& rc, LPCTSTR pstrText, DWORD dwTextColor, int iFont, UINT uStyle);
		static void DrawHtmlText(HDC hDC, CPaintManagerUI* pManager, RECT& rc, LPCTSTR pstrText, DWORD dwTextColor, RECT* pLinks, CDuiString* sLinks, int& nLinkRects, int iFont, UINT uStyle);

		// 检查颜色的alpha通道
		static void CheckAlphaColor(DWORD& dwColor);
		static DWORD AdjustColor(DWORD dwColor, short H, short S, short L);

		static HBITMAP CreateARGB32Bitmap(HDC hDC, int cx, int cy, BYTE** pBits);
		static void AdjustImage(bool bUseHSL, TImageInfo* imageInfo, short H, short S, short L);

		static HBITMAP GenerateBitmap(CPaintManagerUI* pManager, RECT rc, CControlUI* pStopControl = NULL, DWORD dwFilterColor = 0);
		static HBITMAP GenerateBitmap(CPaintManagerUI* pManager, CControlUI* pControl, RECT rc, DWORD dwFilterColor = 0);
		static SIZE GetTextSize(HDC hDC, CPaintManagerUI* pManager , LPCTSTR pstrText, int iFont, UINT uStyle);

	};

} // namespace DuiLib

#endif // __UIRENDER_H__
