/*****************************************************************************
* Copyright (C) 2013 x265 project
*
* Author: Gopu Govindaswamy <gopu@multicorewareinc.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
*
* This program is also available under a commercial proprietary license.
* For more information, contact us at license @ x265.com.
*****************************************************************************/

#ifndef X265_DEBLOCK_H
#define X265_DEBLOCK_H

#include "common.h"

namespace x265 {
// private namespace

class CUData;
struct CUGeom;

class Deblock
{
public:
    enum { EDGE_VER, EDGE_HOR };

    void deblockCTU(const CUData* ctu, const CUGeom& cuGeom, int32_t dir);

protected:

    // CU-level deblocking function
    void deblockCU(const CUData* cu, const CUGeom& cuGeom, const int32_t dir, uint8_t blockStrength[]);

    // set filtering functions
    void setEdgefilterTU(const CUData* cu, uint32_t absPartIdx, uint32_t tuDepth, int32_t dir, uint8_t blockStrength[]);
    void setEdgefilterPU(const CUData* cu, uint32_t absPartIdx, int32_t dir, uint8_t blockStrength[], uint32_t numUnits);
    void setEdgefilterMultiple(const CUData* cu, uint32_t absPartIdx, int32_t dir, int32_t edgeIdx, uint8_t value, uint8_t blockStrength[], uint32_t numUnits);

    // get filtering functions
    uint8_t getBoundaryStrength(const CUData* cuQ, int32_t dir, uint32_t partQ, const uint8_t blockStrength[]);

    // filter luma/chroma functions
    void edgeFilterLuma(const CUData* cuQ, uint32_t absPartIdx, uint32_t depth, int32_t dir, int32_t edge, const uint8_t blockStrength[]);
    void edgeFilterChroma(const CUData* cuQ, uint32_t absPartIdx, uint32_t depth, int32_t dir, int32_t edge, const uint8_t blockStrength[]);

    static const uint8_t s_tcTable[54];
    static const uint8_t s_betaTable[52];
};
}
#endif // ifndef X265_DEBLOCK_H
