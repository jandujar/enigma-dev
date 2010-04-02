/*********************************************************************************\
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
\*********************************************************************************/

/**Blend Mode Functions********************************************************\

bm_normal, bm_add, bm_max, bm_subtract, bm_zero, bm_one, bm_src_color, 
bm_inv_src_color, bm_src_alpha, bm_inv_src_alpha, bm_dest_alpha, 
bm_inv_dest_alpha, bm_dest_color, bm_inv_dest_color, bm_src_alpha_sat

int draw_set_blend_mode(ARG mode)
int draw_set_blend_mode_ext(ARG src,ARG2 dest)

\******************************************************************************/

const int bm_normal   =0;
const int bm_add      =1;
const int bm_max      =2;
const int bm_subtract =3;

const int bm_zero             =1;  //GL_ZERO
const int bm_one              =2;  //GL_ONE
const int bm_src_color        =3;  ////GL_SRC_COLOR             //only for dest
const int bm_inv_src_color    =4;  ////GL_ONE_MINUS_SRC_COLOR   //only for dest
const int bm_src_alpha        =5;  //GL_SRC_ALPHA
const int bm_inv_src_alpha    =6;  //GL_ONE_MINUS_SRC_ALPHA
const int bm_dest_alpha       =7;  //GL_DST_ALPHA
const int bm_inv_dest_alpha   =8;  //GL_ONE_MINUS_DST_ALPHA
const int bm_dest_color       =9;  ///GL_DST_COLOR              //only for src
const int bm_inv_dest_color   =10; ///GL_ONE_MINUS_DST_COLOR    //only for src
const int bm_src_alpha_sat    =11; ///GL_SRC_ALPHA_SATURATE     //only for src

int draw_set_blend_mode(int mode)
{
    switch (mode)
    {
        case 0: //bm_normal
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             return 0;
        case 1: //bm_add
             glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA);
             return 0;
        case 2: //bm_max
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_COLOR);
             return 0;
        case 3: //bm_subtract
             glBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_COLOR);
             return 0;
        default:
             glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
             return 0;
    }
}

int draw_set_blend_mode_ext(int src,int dest)
{
    int source,dst;
    switch (src) { case 1: source=GL_ZERO; break;
                   case 2: source=GL_ONE; break;
                   case 3: source=GL_SRC_COLOR;  break;
                   case 4: source=GL_ONE_MINUS_SRC_COLOR;  break;
                   case 5: source=GL_SRC_ALPHA;  break;
                   case 6: source=GL_ONE_MINUS_SRC_ALPHA;  break;
                   case 7: source=GL_DST_ALPHA;  break;
                   case 8: source=GL_ONE_MINUS_DST_ALPHA;  break;
                   case 9: source=GL_DST_COLOR;  break;
                   case 10: source=GL_ONE_MINUS_DST_COLOR;  break;
                   case 11: source=GL_SRC_ALPHA_SATURATE;  break; }
    switch (dest) { case 1: dst=GL_ZERO; break;
                   case 2: dst=GL_ONE; break;
                   case 3: dst=GL_SRC_COLOR;  break;
                   case 4: dst=GL_ONE_MINUS_SRC_COLOR;  break;
                   case 5: dst=GL_SRC_ALPHA;  break;
                   case 6: dst=GL_ONE_MINUS_SRC_ALPHA;  break;
                   case 7: dst=GL_DST_ALPHA;  break;
                   case 8: dst=GL_ONE_MINUS_DST_ALPHA;  break;
                   case 9: dst=GL_DST_COLOR;  break;
                   case 10: dst=GL_ONE_MINUS_DST_COLOR;  break;
                   case 11: dst=GL_SRC_ALPHA_SATURATE;  break; }
    glBlendFunc(source,dst);
    
    return 0;
}