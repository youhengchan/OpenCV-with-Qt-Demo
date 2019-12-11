/*
 * This file is part of wsapps & wslibs.
 *
 * Wslibs & Wsapps is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Wslibs & Wsapps distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Wslibs & Wsapps; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#ifndef _wsmatrix_h_
#define _wsmatrix_h_
namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{
class WsMatrix
{
public:
	WsMatrix();
	WsMatrix(int row,int col);
	WsMatrix(int row,int col,int *_data);
	WsMatrix & operator =(const WsMatrix &matrix);
	~WsMatrix();
	int get(int row,int col);
	void set(int row,int col,int value);
	inline int row(){return m_row;}
	inline int col(){return m_col;}
private:	
	int m_row;
	int m_col;
	int *m_data;	

};
	}//wslibs
}//wsbaswidgets
#endif
