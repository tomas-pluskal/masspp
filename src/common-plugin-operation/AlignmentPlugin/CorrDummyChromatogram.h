/**
 * @file CorrDummyChromatogram.h
 * @brief interfaces of CorrDummyChromatogram class
 *
 * @author S.Tanaka
 * @date 2007.08.22
 * 
 * Copyright(C) 2006-2014 Eisai Co., Ltd. All rights reserved.
 */


#ifndef __KOME_ALIGNMENT_CORR_DUMMY_CHROMATOGRAM_H__
#define __KOME_ALIGNMENT_CORR_DUMMY_CHROMATOGRAM_H__


namespace kome {
	namespace alignment {

		/**
		 * @class CorrDummyChromatogram
		 * @brief dummy chromatogram class to draw correction graph
		 */
		class CorrDummyChromatogram : public kome::objects::Chromatogram {
		public:
			/**
			 * @fn CorrDummyChromatogram()
			 * @brief constructor
			 */
			CorrDummyChromatogram();

			/**
			 * @fn virtual ~CorrDummyChromatogram()
			 * @brief destructor
			 */
			virtual ~CorrDummyChromatogram();

		protected:
			/**
			 * @fn virtual void onGetXYData( kome::core::XYData* const xyData )
			 * @brief gets chromatogram data points (override method)
			 * @param xyData object to store data points
			 */
			virtual void onGetXYData( kome::core::XYData* const xyData );

			/**
			 * @fn virtual void onGetSpectra(
					kome::objects::DataSet& dataSet,
					const double startRt,
					const double endRt,
					const kome::objects::SearchType startSearch,
					const kome::objects::SearchType endSearch
				)
			 * @brief This method is called by searchSpectrum or getSpectra method (override method)
			 * @param spectra spectra object to store spectra
			 * @param startRt start RT
			 * @param endRt end RT
			 * @param startSearch start search type
			 * @param endSearch end search type
			 */
			virtual void onGetSpectra(
				kome::objects::DataSet& dataSet,
				const double startRt,
				const double endRt,
				const kome::objects::SearchType startSearch,
				const kome::objects::SearchType endSearch
			);

			/**
			 * @fn virtual double onGetMass( const unsigned int index )
			 * @brief This method is called by getMass method (override method)
			 * @param index data index
			 * @return mass
			 */
			virtual double onGetMass( const unsigned int index );

			/**
			 * @fn virtual int onGetMsStage( const unsigned int index )
			 * @brief This method is called by getMsStage method (override method)
			 * @param index data index
			 * @return MS stage.
			 */
			virtual int onGetMsStage( const unsigned int index );

			/**
			 * @fn virtual double onGetPrecursor( const unsigned int index )
			 * @brief This method is called by getPrecursor method (override method)
			 * @param index data index
			 * @return precursor mass
			 */
			virtual double onGetPrecursor( const unsigned int index );
		};
	}
}


#endif		// __KOME_ALIGNMENT_CORR_DUMMY_CHROMATOGRAM_H__
