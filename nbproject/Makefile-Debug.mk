#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BackToFront.o \
	${OBJECTDIR}/Chord.o \
	${OBJECTDIR}/ChordGen.o \
	${OBJECTDIR}/ChordGenStrategy.o \
	${OBJECTDIR}/ChordSequence.o \
	${OBJECTDIR}/FrontToBack.o \
	${OBJECTDIR}/RhythmGenerator.o \
	${OBJECTDIR}/Scale.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chordgen.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chordgen.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chordgen ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/BackToFront.o: BackToFront.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/BackToFront.o BackToFront.cpp

${OBJECTDIR}/Chord.o: Chord.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/Chord.o Chord.cpp

${OBJECTDIR}/ChordGen.o: ChordGen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/ChordGen.o ChordGen.cpp

${OBJECTDIR}/ChordGenStrategy.o: ChordGenStrategy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/ChordGenStrategy.o ChordGenStrategy.cpp

${OBJECTDIR}/ChordSequence.o: ChordSequence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/ChordSequence.o ChordSequence.cpp

${OBJECTDIR}/FrontToBack.o: FrontToBack.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/FrontToBack.o FrontToBack.cpp

${OBJECTDIR}/RhythmGenerator.o: RhythmGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/RhythmGenerator.o RhythmGenerator.cpp

${OBJECTDIR}/Scale.o: Scale.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/Scale.o Scale.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/../chord_gen -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chordgen.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
