#    Copyright (C) 2021  Agustín Ranieri
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.

# Agregar bibliotecas necesarias acá (por ejemplo, -lm para incluir <math.h>)
LIBS+= -lm

CC=gcc
#LEX=flex

EXT=out

ifeq ($(OS),Windows_NT)
	EXT=exe
	C_FLAGS+=-m32
endif

all:
	gcc test.c ../src/main.c -o test.out

clean:
	rm -rf test.out
