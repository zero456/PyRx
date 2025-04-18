#pragma once

#include "PyDbObjectId.h"
#pragma pack (push, 8)

class PyRxClass;
class AdsName;
typedef std::array<int64_t, 2> PySSName;

void makePyEdSelectionSetWrapper();

class PyEdSelectionSet
{
public:
    PyEdSelectionSet();
    PyEdSelectionSet(const ads_name& ss);
    PyEdSelectionSet(const ads_name& ss, bool autoDelete);
    ~PyEdSelectionSet() = default;
    bool			    isInitialized() const;
    size_t              size() const;
    void                clear();
    void                add(const PyDbObjectId& objId);
    void                remove(const PyDbObjectId& objId);
    bool                hasMember(const PyDbObjectId& objId);
    AdsName             adsname() const;
    bool                ssSetFirst();
    Acad::PromptStatus  ssXform(const AcGeMatrix3d& xform);
    boost::python::list ssNameX1();
    boost::python::list ssNameX2(int ind);
    boost::python::list objectIds();
    boost::python::list objectIdsOfType(const PyRxClass& _class);
    boost::python::list objectIdsOfTypeList(const boost::python::list& _classes);//must be list
    void                forceKeepAlive(bool keepIt);
    AcDbObjectIdArray   objectIdsImpl() const;
public:
    void filliterator();
    std::vector<PyDbObjectId>::iterator begin();
    std::vector<PyDbObjectId>::iterator end();
    std::vector<PyDbObjectId> m_iterable{ 0 };
public:
    PySSName* impObj(const std::source_location& src = std::source_location::current()) const;
public:
    std::shared_ptr<PySSName> m_pSet;
};

#pragma pack (pop)
