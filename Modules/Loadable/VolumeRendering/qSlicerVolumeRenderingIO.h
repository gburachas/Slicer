/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerVolumeRenderingIO_h
#define __qSlicerVolumeRenderingIO_h

// SlicerQT includes
#include <qSlicerFileReader.h>

// Volume Rendering includes
class qSlicerVolumeRenderingIOPrivate;
class vtkSlicerVolumeRenderingLogic;

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_VolumeRendering
class qSlicerVolumeRenderingIO
  : public qSlicerFileReader
{
  Q_OBJECT
public:
  typedef qSlicerFileReader Superclass;
  qSlicerVolumeRenderingIO(QObject* parent = 0);
  qSlicerVolumeRenderingIO(vtkSlicerVolumeRenderingLogic* logic, QObject* parent = 0);
  virtual ~qSlicerVolumeRenderingIO();

  void setVolumeRenderingLogic(vtkSlicerVolumeRenderingLogic* logic);
  vtkSlicerVolumeRenderingLogic* volumeRenderingLogic()const;

  // Reimplemented for IO specific description
  virtual QString description()const;
  virtual IOFileType fileType()const;
  virtual QStringList extensions()const;

  virtual bool load(const IOProperties& properties);

protected:
  QScopedPointer<qSlicerVolumeRenderingIOPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerVolumeRenderingIO);
  Q_DISABLE_COPY(qSlicerVolumeRenderingIO);
};

#endif
