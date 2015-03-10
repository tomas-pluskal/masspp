/**
 * @file CorrectionPanel.h
 * @brief interfaces of CorrectionPanel class
 *
 * @author S.Tanaka
 * @date 2007.08.22
 * 
 * Copyright(C) 2006-2014 Eisai Co., Ltd. All rights reserved.
 */


#ifndef __KOME_ALIGNMENT_CORRECTION_PANEL_H__
#define __KOME_ALIGNMENT_CORRECTION_PANEL_H__


#include "PanelBase.h"


namespace kome {
	namespace alignment {

		class CorrectionCanvas;

		/**
		 * @class CorrectionPanel
		 * @brief correction panel class
		 */
		class CorrectionPanel : public PanelBase {
		public:
			/**
			 * @fn CorrectionPanel( wxWindow* parent )
			 * @brief constructor
			 * @param parent parent window
			 */
			CorrectionPanel( wxWindow* parent );

			/**
			 * @fn virtual ~CorrectionPanel()
			 * @brief destructor
			 */
			virtual ~CorrectionPanel();

		protected:
			/** correction canvas */
			CorrectionCanvas* m_canvas;

		protected:
			/**
			 * @fn virtual wxSizer* createMainSizer()
			 * @brief creates main sizer
			 * @return main sizer
			 */
			virtual wxSizer* createMainSizer();

		private:
			DECLARE_EVENT_TABLE()
		};
	}
}

#endif		// __KOME_ALIGNMENT_CORRECTION_PANEL_H__
