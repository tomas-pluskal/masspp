/**
 * @file MgfSpectrum.h
 * @brief interfaces of MgfSpectrum class
 *
 * @author M.Izumi
 * @date 2013.07.18
 * 
 * Copyright(C) 2006-2014 Eisai Co., Ltd. All rights reserved.
 */

#ifndef __KOME_IDENT_MGF_SPECTRUM_H__
#define __KOME_IDENT_MGF_SPECTRUM_H__

namespace kome {
	namespace ident {
		class MgfSample;

		class MgfSpectrum : public kome::objects::Spectrum {
		public:
			MgfSpectrum( MgfSample* sample, const char* name );

			virtual ~MgfSpectrum();

		protected:
			MgfSample* m_mgfSample;

			std::string m_tmpPointPath;

			double m_minMz;
			double m_maxMz;

		public:
			void setPointPath( const char* path ){ m_tmpPointPath = path; }
			const char* getPointPath(){ return m_tmpPointPath.c_str(); }

			void addPoint( const double x, const double y );
		protected:
			/**
			 * @fn virtual void onGetXYData( kome::core::XYData* const xyData, const double minX, const double maxX )
			 * @brief This method is called by getXYData method. (override method)
			 * @param xyData the object to store data points
			 * @param minX minimum x value. (If minX is negative number, minimum x value is not unbounded.)
			 * @param maxX maximum x value. (If maxX is negative number, maximum x value is not unbounded.)
			 */
			virtual void onGetXYData( kome::core::XYData* const xyData, const double minX, const double maxX );

			/**
			 * @fn virtual void onGetXRange( double* minX, double* maxX )
			 * @brief This method is called by getMinX or getMaxX method. (override method)
			 * @param minX the pointer to store minimum x value
			 * @param maxX the pointer to store maximum x value
			 */
			virtual void onGetXRange( double* minX, double* maxX );

			/**
			 * @fn virtual double onGetTotalIntensity( const double minX, const double maxX )
			 * @brief This method is called by getTotalIntensity method. (override method)
			 * @param minX minimum x of range (If minX is negative number, minimum x value is unbounded.)
			 * @param maxX maximum x of range (If maxX is negative number, maximum x value is unbounded.)
			 * @return total intensity
			 */
			virtual double onGetTotalIntensity( const double minX, const double maxX );

			/**
			 * @fn virtual double onGetMaxIntensity( const double minX, const double maxX )
			 * @brief This method is called by getMaxIntensity method. (override method)
			 * @param minX minimum x of range (If minX is negative number, minimum x value is unbounded.)
			 * @param maxX maximum x of range (If maxX is negative number, maximum x value is unbounded.)
			 * @return max intensity
			 */
			virtual double onGetMaxIntensity( const double minX, const double maxX );

			// >>>>>> @Date:2013/09/05	<Add>	A.Ozaki
			//
			/**
			 * @fn virtual  bool onSetRequestLoadData( void )
			 * @brief This method is called by setRequestLoadData method. (abstract method)
			 */
			virtual void	onSetRequestLoadData( void );
			/**
			 * @fn virtual  bool onResetRequestLoadData( void )
			 * @brief This method is called by resetRequestLoadData method. (abstract method)
			 */
			virtual void	onResetRequestLoadData( void );
			
			/**
			 * @fn virtual  bool onIsRequestLoadData( void )
			 * @brief This method is called by isRequestLoadData method. (abstract method)
			 * @return If true, file read request is valid.
			 */
			virtual bool	onIsRequestLoadData( void );

			/**
			 * @fn virtual  bool onSetFirstAccess( void )
			 * @brief This method is called by setFirstAccess method. (abstract method)
			 */
			virtual void	onSetFirstAccess( void );

			/**
			 * @fn virtual  bool onResetFirstAccess( void )
			 * @brief This method is called by resetFirstAccess method. (abstract method)
			 */
			virtual void	onResetFirstAccess( void );
			
			/**
			 * @fn virtual  bool onIsFirstAccess( void )
			 * @brief This method is called by isFirstAccess method. (abstract method)
			 * @return If true, the first accessing.
			 */
			virtual bool	onIsFirstAccess( void );
			
			/**
			 * @fn virtual  bool onLoadData( void )
			 * @brief This method is called by loadData method. (abstract method)
			 * @return If true, file reading success.
			 */
			virtual bool	onLoadData( void );
			//
			// <<<<<< @Date:2013/09/05	<Add>	A.Ozaki

		};
	}
}

#endif // __KOME_IDENT_MGF_SPECTRUM_H__
