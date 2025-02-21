Pipeline Processing System

Overview

This project is a pipeline-based processing system designed to handle various data types, such as ZIP archives, images, and JSON files. The system processes input files through a sequence of actions, dynamically applying transformations based on the file type.


Features:

 - Modular pipeline: Supports adding custom actions.

 - Automatic type detection: Determines the file type and applies appropriate actions.

 - Sequential processing: Each file goes through all applicable processing steps.

 - Queue-based execution: Ensures proper handling of multiple files.


Supported Actions:

 - LoadFileAction: Reads file content into memory.

 - ExtractZipAction: Extracts ZIP archives and adds extracted files back into the pipeline.

 - ImgDecodeAction: Decodes and processes image files.

 - JSONParseAction: Parses JSON files for further use.


Installation:

Prerequisites

C++17 or later

CMake (for building the project)


Build Instructions:

1) Clone the repository:

 $ git clone https://github.com/your-repo/pipeline-project.git
 $ cd pipeline-project

2) Create a build directory and compile:

mkdir build && cd build
cmake ..
make


Usage:

Run the compiled executable:

./ComputePipeline


The pipeline will process predefined files:

/path/to/archive.zip

/path/to/file.json

/path/to/image.jpg


Adding Custom Actions

To add a new action:

Implement a new class derived from Action<T>.

Override the canProcess() and process() methods.

Register the action in Pipeline::addAction() before execution.


Example:

Pipeline pipeline;

pipeline.addAction(std::make_unique<LoadFileAction<std::string>>());
pipeline.addAction(std::make_unique<ExtractZipAction>());
pipeline.addAction(std::make_unique<ImgDecodeAction>());
pipeline.addAction(std::make_unique<JSONParseAction>());

pipeline.addInput("/path/to/sample.zip");
pipeline.process();



Directory Structure:

ComputePipeline/
│── out/
│   └── (contains compiled files)
│
│── Private/
│   └── Pipeline.cpp  (implementation of the pipeline, not exposed to public API)
│
│── Public/
│   │── Actions/
│   │   ├── Action.h  (base class for actions)
│   │   ├── ExtractZipAction.h  (handles ZIP extraction)
│   │   ├── ImgDecodeAction.h  (handles image decoding)
│   │   ├── JSONParseAction.h  (parses JSON data)
│   │   ├── LoadFileAction.h  (loads files)
│   │
│   ├── DataObject.h  (data container)
│   ├── MetaData.h  (metadata structure)
│   ├── Pipeline.h  (pipeline definition)
│   ├── Utility.h  (helper functions)
│
│── CMakeLists.txt  (CMake project configuration)
│── CMakePresets.json  (CMake presets)
│── ComputePipeline.cpp  (main entry point)
│── ComputePipeline.h  (main project header)
│── README.md  (project documentation)

License

This project is licensed under the ***** License. See LICENSE for details.

