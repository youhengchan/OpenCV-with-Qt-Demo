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
#include <stdlib.h>
#include <string.h>
#include "wsmatrix.h"
namespace namespace_wslibs{
	namespace namespace_wsbaswidgets{
WsMatrix::WsMatrix()
{
	m_row = 0;
	m_col = 0;
	m_data = NULL;
}
WsMatrix::WsMatrix(int row,int col)
{
	m_row = row;
	m_col = col;
	m_data = NULL; 
}
WsMatrix::WsMatrix(int row,int col,int *_data)
{
	m_row = row;
	m_col = col;
	m_data = _data; 
}
WsMatrix & WsMatrix::operator =(const WsMatrix &matrix)
{
	if(this->m_data)
		free(this->m_data);
	this->m_row = matrix.m_row;
	this->m_col = matrix.m_col;
	this->m_data = (int*)strdup((char*)matrix.m_data);
	return *this;
}
WsMatrix::~WsMatrix()
{
	if(m_data)
		free(m_data);
}
int WsMatrix::get(int row,int col)
{
	return m_data[col * m_row + row];
}
void WsMatrix::set(int row,int col,int value)
{
	m_data[row * m_row + col] = value;
}
	}//wslibs
}//wsbaswidgets

