/****************************************************************************
** Meta object code from reading C++ file 'WaveformModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/model/WaveformModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WaveformModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WaveformModel_t {
    QByteArrayData data[26];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WaveformModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WaveformModel_t qt_meta_stringdata_WaveformModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "WaveformModel"
QT_MOC_LITERAL(1, 14, 10), // "imageReady"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "bpmChanged"
QT_MOC_LITERAL(4, 37, 19), // "peakPressureChanged"
QT_MOC_LITERAL(5, 57, 17), // "etco2ValueChanged"
QT_MOC_LITERAL(6, 75, 11), // "spo2Changed"
QT_MOC_LITERAL(7, 87, 22), // "respiratoryRateChanged"
QT_MOC_LITERAL(8, 110, 18), // "tidalVolumeChanged"
QT_MOC_LITERAL(9, 129, 16), // "peepValueChanged"
QT_MOC_LITERAL(10, 146, 16), // "fio2ValueChanged"
QT_MOC_LITERAL(11, 163, 19), // "batteryLevelChanged"
QT_MOC_LITERAL(12, 183, 19), // "wifiStrengthChanged"
QT_MOC_LITERAL(13, 203, 11), // "renderFrame"
QT_MOC_LITERAL(14, 215, 2), // "dt"
QT_MOC_LITERAL(15, 218, 13), // "waveformImage"
QT_MOC_LITERAL(16, 232, 3), // "bpm"
QT_MOC_LITERAL(17, 236, 12), // "peakPressure"
QT_MOC_LITERAL(18, 249, 10), // "etco2Value"
QT_MOC_LITERAL(19, 260, 4), // "spo2"
QT_MOC_LITERAL(20, 265, 15), // "respiratoryRate"
QT_MOC_LITERAL(21, 281, 11), // "tidalVolume"
QT_MOC_LITERAL(22, 293, 9), // "peepValue"
QT_MOC_LITERAL(23, 303, 9), // "fio2Value"
QT_MOC_LITERAL(24, 313, 12), // "batteryLevel"
QT_MOC_LITERAL(25, 326, 12) // "wifiStrength"

    },
    "WaveformModel\0imageReady\0\0bpmChanged\0"
    "peakPressureChanged\0etco2ValueChanged\0"
    "spo2Changed\0respiratoryRateChanged\0"
    "tidalVolumeChanged\0peepValueChanged\0"
    "fio2ValueChanged\0batteryLevelChanged\0"
    "wifiStrengthChanged\0renderFrame\0dt\0"
    "waveformImage\0bpm\0peakPressure\0"
    "etco2Value\0spo2\0respiratoryRate\0"
    "tidalVolume\0peepValue\0fio2Value\0"
    "batteryLevel\0wifiStrength"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WaveformModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
      11,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,
      10,    0,   82,    2, 0x06 /* Public */,
      11,    0,   83,    2, 0x06 /* Public */,
      12,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,   14,

 // properties: name, type, flags
      15, QMetaType::QImage, 0x00495001,
      16, QMetaType::Double, 0x00495001,
      17, QMetaType::Double, 0x00495001,
      18, QMetaType::Double, 0x00495001,
      19, QMetaType::Double, 0x00495001,
      20, QMetaType::Double, 0x00495001,
      21, QMetaType::Double, 0x00495001,
      22, QMetaType::Double, 0x00495001,
      23, QMetaType::Double, 0x00495001,
      24, QMetaType::Int, 0x00495001,
      25, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,
      10,

       0        // eod
};

void WaveformModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WaveformModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->imageReady(); break;
        case 1: _t->bpmChanged(); break;
        case 2: _t->peakPressureChanged(); break;
        case 3: _t->etco2ValueChanged(); break;
        case 4: _t->spo2Changed(); break;
        case 5: _t->respiratoryRateChanged(); break;
        case 6: _t->tidalVolumeChanged(); break;
        case 7: _t->peepValueChanged(); break;
        case 8: _t->fio2ValueChanged(); break;
        case 9: _t->batteryLevelChanged(); break;
        case 10: _t->wifiStrengthChanged(); break;
        case 11: _t->renderFrame((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::imageReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::bpmChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::peakPressureChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::etco2ValueChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::spo2Changed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::respiratoryRateChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::tidalVolumeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::peepValueChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::fio2ValueChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::batteryLevelChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (WaveformModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WaveformModel::wifiStrengthChanged)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WaveformModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QImage*>(_v) = _t->waveformImage(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->bpm(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->peakPressure(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->etco2Value(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->spo2(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->respiratoryRate(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->tidalVolume(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->peepValue(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->fio2Value(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->batteryLevel(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->wifiStrength(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject WaveformModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WaveformModel.data,
    qt_meta_data_WaveformModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WaveformModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaveformModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WaveformModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WaveformModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WaveformModel::imageReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WaveformModel::bpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WaveformModel::peakPressureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WaveformModel::etco2ValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WaveformModel::spo2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WaveformModel::respiratoryRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WaveformModel::tidalVolumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void WaveformModel::peepValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void WaveformModel::fio2ValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void WaveformModel::batteryLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void WaveformModel::wifiStrengthChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
