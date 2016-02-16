/*
 *   Copyright (C) 2015,2016 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(TFTSERIAL_H)
#define	TFTSERIAL_H

#include "Display.h"
#include "SerialController.h"

#include <string>

class CTFTSerial : public IDisplay
{
public:
  CTFTSerial(const std::string& port);
  virtual ~CTFTSerial();

  virtual bool open();

  virtual void setIdle();

  virtual void setDStar();
  virtual void writeDStar(const std::string& call1, const std::string& call2);
  virtual void clearDStar();

  virtual void setDMR();
  virtual void writeDMR(unsigned int slotNo, unsigned int srdId, bool group, unsigned int dstId);
  virtual void clearDMR(unsigned int slotNo);

  virtual void setFusion();
  virtual void writeFusion(const std::string& callsign);
  virtual void clearFusion();

  virtual void close();

private:
  CSerialController m_serial;

  void clearScreen();
  void writeText(unsigned char x, unsigned char y, const char* text);
  void writeImage(unsigned char x, unsigned char y, const char* filename);
};

#endif
