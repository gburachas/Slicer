/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) 
  All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer

=========================================================================auto=*/

#include "vtkMRMLStorableNode.h"


#include "vtkMRMLCoreTestingMacros.h"

#include "vtkMRMLModelStorageNode.h"

class vtkMRMLStorableNodeTestHelper1 : public vtkMRMLStorableNode
{
public:
  // Provide a concrete New.
  static vtkMRMLStorableNodeTestHelper1 *New(){return new vtkMRMLStorableNodeTestHelper1;};

  vtkTypeMacro( vtkMRMLStorableNodeTestHelper1,vtkMRMLStorableNode);

  virtual vtkMRMLNode* CreateNodeInstance()
    {
    return new vtkMRMLStorableNodeTestHelper1;
    }
  virtual const char* GetNodeTagName()
    {
    return "vtkMRMLStorableNodeTestHelper1";
    }

  // for testing purposes, return a valid storage node,
  // vtkMRMLStorageNode::New returns NULL
  virtual vtkMRMLStorageNode* CreateDefaultStorageNode() { return vtkMRMLModelStorageNode::New(); }
};
 
int vtkMRMLStorableNodeTest1(int , char * [] )
{
  vtkSmartPointer< vtkMRMLStorableNodeTestHelper1 > node1 = vtkSmartPointer< vtkMRMLStorableNodeTestHelper1 >::New();

  EXERCISE_BASIC_OBJECT_METHODS( node1 );

  EXERCISE_BASIC_STORABLE_MRML_METHODS(vtkMRMLStorableNodeTestHelper1, node1);
  
  return EXIT_SUCCESS;
}
