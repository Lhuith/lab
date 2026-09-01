# Install script for directory: /mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/i686-w64-mingw32-objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibassimp5.4.1-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/lib/libassimp.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/anim.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/aabb.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ai_assert.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/camera.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/color4.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/color4.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/config.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ColladaMetaData.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/commonMetaData.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/defs.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/cfileio.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/light.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/material.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/material.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/matrix3x3.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/matrix3x3.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/matrix4x4.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/matrix4x4.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/mesh.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ObjMaterial.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/pbrmaterial.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/GltfMaterial.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/postprocess.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/quaternion.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/quaternion.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/scene.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/metadata.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/texture.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/types.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/vector2.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/vector2.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/vector3.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/vector3.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/version.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/cimport.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/AssertHandler.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/importerdesc.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Importer.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/DefaultLogger.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ProgressHandler.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/IOStream.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/IOSystem.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Logger.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/LogStream.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/NullLogger.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/cexport.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Exporter.hpp"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/DefaultIOStream.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/DefaultIOSystem.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ZipArchiveIOSystem.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SceneCombiner.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/fast_atof.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/qnan.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/BaseImporter.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Hash.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/MemoryIOWrapper.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ParsingUtils.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/StreamReader.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/StreamWriter.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/StringComparison.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/StringUtils.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SGSpatialSort.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/GenericProperty.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SpatialSort.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SkeletonMeshBuilder.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SmallVector.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SmoothingGroups.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/SmoothingGroups.inl"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/StandardShapes.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/RemoveComments.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Subdivision.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Vertex.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/LineSplitter.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/TinyFormatter.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Profiler.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/LogAux.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Bitmap.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/XMLTools.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/IOStreamBuffer.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/CreateAnimMesh.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/XmlParser.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/BlobIOSystem.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/MathFunctions.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Exceptional.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/ByteSwapper.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Base64.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Compiler/pushpack1.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Compiler/poppack1.h"
    "/mnt/d/Studies/Online/Computer Graphics with Modern OpenGL and C++/Libs/ASSIMP/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

