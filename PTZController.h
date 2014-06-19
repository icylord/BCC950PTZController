#ifndef __PTZCONTROLLER_H__
#define __PTZCONTROLLER_H__

/*!
 * \file PTZController.h
 * \brief implementation Pan/Tile/Zoom controller
 * \author Shengyin Wu
 * \date 2014.06.18
 */

#include <dshow.h>
#include <Ks.h>	
#include <KsMedia.h>
#include <memory>

#pragma comment(lib, "strmiids.lib")

class BCC950Controller;

class PTZController
{
public:
	PTZController(const int camera_index);
	~PTZController();

	/// \brief Pan control function  
	/// \param step step > 0 -> turn right, step < 0 -> turn left   
	/// \return void
	void pan(int step); // left to right 9 level
	/// \brief Tilt control function  
	/// \param step step > 0 -> turn up, step < 0 -> turn down   
	/// \return void
	void tilt(int step); // up to down 9 level
	/// \brief Zoom control function  
	/// \param step step > 0 -> zoom bigger, step < 0 -> zoom smaller   
	/// \return void
	void zoom(int step); //

private:
	PTZController(const PTZController& BCC950_controller) {}
	PTZController& operator=(const PTZController& BCC950_controller) {}
	std::shared_ptr<BCC950Controller> controller_;
};

#endif