/*******************************************************************************
 * libretroshare/src/retroshare: rsiface.h                                     *
 *                                                                             *
 * libretroshare: retroshare core library                                      *
 *                                                                             *
 * Copyright 2004-2006 by Robert Fernie <retroshare@lunamutt.com>              *
 *                                                                             *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU Lesser General Public License as              *
 * published by the Free Software Foundation, either version 3 of the          *
 * License, or (at your option) any later version.                             *
 *                                                                             *
 * This program is distributed in the hope that it will be useful,             *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *
 * GNU Lesser General Public License for more details.                         *
 *                                                                             *
 * You should have received a copy of the GNU Lesser General Public License    *
 * along with this program. If not, see <https://www.gnu.org/licenses/>.       *
 *                                                                             *
 *******************************************************************************/
#ifndef RETROSHARE_GUI_INTERFACE_H
#define RETROSHARE_GUI_INTERFACE_H

#include "retroshare/rsnotify.h"
#include "rstypes.h"

#include <map>

class NotifyBase;
class RsServer;
class RsInit;
class RsPeerCryptoParams;
struct TurtleFileInfo ;

/* RsInit -> Configuration Parameters for RetroShare Startup
 */

RsInit *InitRsConfig();
/* extract various options for GUI */
const char   *RsConfigDirectory(RsInit *config);
bool    RsConfigStartMinimised(RsInit *config);
void    CleanupRsConfig(RsInit *);


// Called First... (handles comandline options) 
int InitRetroShare(int argc, char **argv, RsInit *config);

class RsControl /* The Main Interface Class - for controlling the server */
{
public:
	/// TODO: This should return a reference instead of a pointer!
	static RsControl *instance();
	static void earlyInitNotificationSystem() { instance(); }

		/* Real Startup Fn */
		virtual int StartupRetroShare() = 0;

		/****************************************/
		/* Config */

		virtual void    ConfigFinalSave( ) 			   = 0;
		virtual void 	rsGlobalShutDown( )			   = 0;

		/****************************************/

		virtual bool getPeerCryptoDetails(const RsPeerId& ssl_id,RsPeerCryptoParams& params) = 0;
		virtual void getLibraries(std::list<RsLibraryInfo> &libraries) = 0;

	protected:
		RsControl() {}	// should not be used, hence it's private.
};


#endif
