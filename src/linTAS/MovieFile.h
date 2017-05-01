/*
    Copyright 2015-2016 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LINTAS_MOVIEFILE_H_INCLUDED
#define LINTAS_MOVIEFILE_H_INCLUDED

//#include <stdio.h>
//#include <unistd.h>
#include "../shared/AllInputs.h"
#include "Context.h"
#include <fstream>
#include <string>

class MovieFile {
public:
    void open(Context* c);
    void importMovie();
    void exportMovie();
    void writeHeader();
    void readHeader();
    int writeFrame(unsigned long frame, AllInputs inputs);
    int readFrame(unsigned long frame, AllInputs& inputs);
    void truncate();
    void close();
private:
    Context* context;
    std::string movie_dir;
    std::fstream input_stream;
};

#endif