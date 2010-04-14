/********************************************************************************\
**                                                                              **
**  Copyright (C) 2008 Josh Ventura                                             **
**                                                                              **
**  This file is a part of the ENIGMA Development Environment.                  **
**                                                                              **
**                                                                              **
**  ENIGMA is free software: you can redistribute it and/or modify it under the **
**  terms of the GNU General Public License as published by the Free Software   **
**  Foundation, version 3 of the license or any later version.                  **
**                                                                              **
**  This application and its source code is distributed AS-IS, WITHOUT ANY      **
**  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS   **
**  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more       **
**  details.                                                                    **
**                                                                              **
**  You should have recieved a copy of the GNU General Public License along     **
**  with this code. If not, see <http://www.gnu.org/licenses/>                  **
**                                                                              **
**  ENIGMA is an environment designed to create games and other programs with a **
**  high-level, fully compilable language. Developers of ENIGMA or anything     **
**  associated with ENIGMA are in no way responsible for its users or           **
**  applications created by its users, or damages caused by the environment     **
**  or programs made in the environment.                                        **
**                                                                              **
\********************************************************************************/

#include <string>
#include <windows.h>

/*namespace enigma //TODO: find the original declaration of the contents of this namespace and erradicate it
{
   extern std::string evname(int num);
   extern int getID();
}*/


namespace enigma //TODO: This is from events.h: fix according to TODO pointed to by above TODO
{
	extern int event_current;
	extern std::string evname(int evnumb);
	extern int getID();
}

extern std::string string(double val);

extern void ABORT_ON_FATAL_ERRORS();
int show_error(std::string errortext,int fatal)
{
  if (MessageBox(NULL,("Error in "+enigma::evname(enigma::event_current) + " event for object number " + string(enigma::getID())+": \r\n"+errortext).c_str(),"Error",MB_ABORTRETRYIGNORE | MB_ICONERROR)==IDABORT)
    exit(0);
		  
	if (fatal)
	{
		printf("FATAL ERROR: %s\n",errortext.c_str());
		exit(0);
	}
	else
	  printf("ERROR: %s\n",errortext.c_str());
  
  ABORT_ON_FATAL_ERRORS();
	return 0;
}