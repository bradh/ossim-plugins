//----------------------------------------------------------------------------
//
// License:  See top level LICENSE.txt file
//
// Author: David Burken
//
// Copied from Mingjie Su's ossimHdfReaderFactory.
//
// Description: Factory for OSSIM HDF reader using HDF5 libraries.
//----------------------------------------------------------------------------
// $Id$

#ifndef ossimH5ReaderFactory_HEADER
#define ossimH5ReaderFactory_HEADER 1

#include <ossim/imaging/ossimImageHandlerFactoryBase.h>

class ossimString;
class ossimFilename;
class ossimKeywordlist;

/** @brief Factory for Hdf image reader. */
class ossimH5ReaderFactory : public ossimImageHandlerFactoryBase
{
public:

   /** @brief virtual destructor */
   virtual ~ossimH5ReaderFactory();

   /**
    * @brief static method to return instance (the only one) of this class.
    * @return pointer to instance of this class.
    */
   static ossimH5ReaderFactory* instance();

   /**
    * @brief open that takes a file name.
    * @param file The file to open.
    * @param openOverview If true image handler will attempt to open overview.
    * default = true 
    * @return pointer to image handler on success, NULL on failure.
    */
   virtual ossimImageHandler* open(const ossimFilename& fileName,
                                   bool openOverview=true) const;

   /**
    * @brief open that takes a keyword list and prefix.
    * @param kwl The keyword list.
    * @param prefix the keyword list prefix.
    * @return pointer to image handler on success, NULL on failure.
    */
   virtual ossimImageHandler* open(const ossimKeywordlist& kwl,
                                   const char* prefix=0)const;

   /**
    * @brief createObject that takes a class name (ossimH5Reader)
    * @param typeName Should be "ossimH5Reader".
    * @return pointer to image writer on success, NULL on failure.
    */
   virtual ossimObject* createObject(const ossimString& typeName)const;
   
   /**
    * @brief Creates and object given a keyword list and prefix.
    * @param kwl The keyword list.
    * @param prefix the keyword list prefix.
    * @return pointer to image handler on success, NULL on failure.
    */
   virtual ossimObject* createObject(const ossimKeywordlist& kwl,
                                     const char* prefix=0)const;
   
   /**
    * @brief Adds ossimH5Reader to the typeList.
    * @param typeList List to add to.
    */
   virtual void getTypeNameList(std::vector<ossimString>& typeList)const;

   /**
    * @brief Method to add supported extension to the list, like "hdf".
    *
    * @param extensionList The list to add to.
    */
   virtual void getSupportedExtensions(
      ossimImageHandlerFactoryBase::UniqueStringList& extensionList)const;
  
protected:

   /**
    * @brief Method to weed out extensions that this plugin knows it does
    * not support.  This is to avoid a costly open on say a tiff or jpeg that
    * is not handled by this plugin.
    *
    * @return true if extension, false if not.
    */
   bool hasExcludedExtension(const ossimFilename& file) const;
   
   /** @brief hidden from use default constructor */
   ossimH5ReaderFactory();

   /** @brief hidden from use copy constructor */
   ossimH5ReaderFactory(const ossimH5ReaderFactory&);

   /** @brief hidden from use copy constructor */
   void operator=(const ossimH5ReaderFactory&);

   /** static instance of this class */
   static ossimH5ReaderFactory* theInstance;

TYPE_DATA
};

#endif /* end of #ifndef ossimH5ReaderFactory_HEADER */

