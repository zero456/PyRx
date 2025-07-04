#include "stdafx.h"
#include "PyGeEntity3d.h"
#include "PyGePlane.h"

using namespace boost::python;

//-----------------------------------------------------------------------------------------
//PyGeEntity3d wrapper
void makePyGeEntity3dWrapper()
{
    PyDocString DS("Entity3d");
    class_<PyGeEntity3d>("Entity3d", boost::python::no_init)
        .def("isKindOf", &PyGeEntity3d::isKindOf, DS.ARGS({ "val : PyGe.EntityId" }))
        .def("type", &PyGeEntity3d::type, DS.ARGS(12055))
        .def("copy", &PyGeEntity3d::copy, DS.ARGS(12044))
        .def("isEqualTo", &PyGeEntity3d::isEqualTo1)
        .def("isEqualTo", &PyGeEntity3d::isEqualTo2, DS.ARGS({ "val : PyGe.Entity3d","tol : PyGe.Tol = ..." }, 12046))
        .def("transformBy", &PyGeEntity3d::transformBy, DS.ARGS({ "val : PyGe.Matrix3d" }, 12053))
        .def("translateBy", &PyGeEntity3d::translateBy, DS.ARGS({ "vec : PyGe.Vector3d" }, 12054))
        .def("rotateBy", &PyGeEntity3d::rotateBy1)
        .def("rotateBy", &PyGeEntity3d::rotateBy2, DS.ARGS({ "angle : float","vec : PyGe.Vector3d","pt : PyGe.Point3d = 'origin'" }, 12051))
        .def("mirror", &PyGeEntity3d::mirror, DS.ARGS({ "val : PyGe.Plane" }, 12049))
        .def("scaleBy", &PyGeEntity3d::scaleBy1)
        .def("scaleBy", &PyGeEntity3d::scaleBy2, DS.ARGS({ "scaleFactor : float","pt : PyGe.Point3d = 'origin'" }, 12052))
        .def("isOn", &PyGeEntity3d::isOn1)
        .def("isOn", &PyGeEntity3d::isOn2, DS.ARGS({ "pt : PyGe.Point3d","tol : PyGe.Tol = ..." }, 12048))
        .def("isNull", &PyGeEntity3d::isNull, DS.ARGS())
        .def("__eq__", &PyGeEntity3d::operator==)
        .def("__ne__", &PyGeEntity3d::operator!=)
        .def("__hash__", &PyGeEntity3d::hash)
        .def("copycast", &PyGeEntity3d::copycast, DS.SARGS({ "otherObject: PyGe.Entity3d" })).staticmethod("copycast")
        .def("className", &PyGeEntity3d::className, DS.SARGS()).staticmethod("className")
        ;
}

struct PyGePyGeEntity3dDeleter
{
    inline PyGePyGeEntity3dDeleter(bool autoDelete)
        : m_autoDelete(autoDelete)
    {
    }

    inline void operator()(AcGeEntity3d* p) const
    {
        if (!m_autoDelete)
            return;
        else
            delete p;
    }
    bool m_autoDelete = true;
};

PyGeEntity3d::PyGeEntity3d(AcGeEntity3d* pEnt)
    : m_imp(pEnt, PyGePyGeEntity3dDeleter(true))
{
}

PyGeEntity3d::PyGeEntity3d(const AcGeEntity3d* pEnt)
    : m_imp(const_cast<AcGeEntity3d*>(pEnt), PyGePyGeEntity3dDeleter(false))
{
}

bool PyGeEntity3d::operator==(PyGeEntity3d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return (m_imp->isEqualTo(*rhs.m_imp));
    return m_imp == rhs.m_imp;
}

bool PyGeEntity3d::operator!=(PyGeEntity3d const& rhs) const
{
    if (!isNull() && !rhs.isNull())
        return !(m_imp->isEqualTo(*rhs.m_imp));
    return m_imp != rhs.m_imp;
}

Adesk::Boolean PyGeEntity3d::isKindOf(AcGe::EntityId entType) const
{
    return impObj()->isKindOf(entType);
}

AcGe::EntityId PyGeEntity3d::type() const
{
    return impObj()->type();
}

PyGeEntity3d PyGeEntity3d::copy() const
{
    return PyGeEntity3d(impObj()->copy());
}

Adesk::Boolean PyGeEntity3d::isEqualTo1(const PyGeEntity3d& ent) const
{
    return impObj()->isEqualTo(*ent.impObj());
}

Adesk::Boolean PyGeEntity3d::isEqualTo2(const PyGeEntity3d& ent, const AcGeTol& tol) const
{
    return impObj()->isEqualTo(*ent.impObj(), tol);
}

void PyGeEntity3d::transformBy(const AcGeMatrix3d& xfm) const
{
    impObj()->transformBy(xfm);
}

void PyGeEntity3d::translateBy(const AcGeVector3d& translateVec) const
{
    impObj()->translateBy(translateVec);
}

void PyGeEntity3d::rotateBy1(double angle, const AcGeVector3d& vec) const
{
    impObj()->rotateBy(angle, vec);
}

void PyGeEntity3d::rotateBy2(double angle, const AcGeVector3d& vec, const AcGePoint3d& wrtPoint) const
{
    impObj()->rotateBy(angle, vec, wrtPoint);
}

void PyGeEntity3d::mirror(const PyGePlane& plane) const
{
    impObj()->mirror(*plane.impObj());
}

void PyGeEntity3d::scaleBy1(double scaleFactor) const
{
    impObj()->scaleBy(scaleFactor);
}

void PyGeEntity3d::scaleBy2(double scaleFactor, const AcGePoint3d& wrtPoint) const
{
    impObj()->scaleBy(scaleFactor, wrtPoint);
}

Adesk::Boolean PyGeEntity3d::isOn1(const AcGePoint3d& pnt) const
{
    return impObj()->isOn(pnt);
}

Adesk::Boolean PyGeEntity3d::isOn2(const AcGePoint3d& pnt, const AcGeTol& tol) const
{
    return impObj()->isOn(pnt, tol);
}

bool PyGeEntity3d::isNull() const
{
    return m_imp == nullptr;
}

std::size_t PyGeEntity3d::hash() const
{
    return std::hash<AcGeEntity3d*>{}(m_imp.get());
}

std::string PyGeEntity3d::className()
{
    return "AcGeEntity3d";
}

PyGeEntity3d PyGeEntity3d::copycast(const PyGeEntity3d& src)
{
    return PyGeEntity3d(static_cast<AcGeEntity3d*>(src.impObj()->copy()));
}

AcGeEntity3d* PyGeEntity3d::impObj(const std::source_location& src /*= std::source_location::current()*/) const
{
    if (m_imp == nullptr) [[unlikely]] {
        throw PyNullObject(src);
    }
    return m_imp.get();
}
