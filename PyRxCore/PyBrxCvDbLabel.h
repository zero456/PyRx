#pragma once

#ifdef BRXAPP
#if !defined(_BRXTARGET240)
#include "PyBrxCvObject.h"
#include "PyDbDate.h"
#include "BrxCvDbStylePartDisplaySettings.h" 
#include "BrxCvDbStyle.h"
#include "BrxCvDbLabelStyleComponent.h"
#include "BrxCvDbLabelStyle.h"
#include "BrxCvDbLabelStyleArrow.h"
#include "BrxCvDbLabelStyleBlock.h"
#include "BrxCvDbLabelStyleLine.h"
#include "BrxCvDbLabelStyleText.h"
#include "BrxCvDbSymbolStyle.h"

class PyDbObjectId;

//-----------------------------------------------------------------------------------
//PyBrxCvDbStylePartDisplaySettings
void makePyBrxCvDbStylePartDisplaySettingsWrapper();

class PyBrxCvDbStylePartDisplaySettings : public PyBrxCvDbSubObject
{
public:
    PyBrxCvDbStylePartDisplaySettings(BrxCvDbStylePartDisplaySettings* ptr, bool autoDelete);
    virtual ~PyBrxCvDbStylePartDisplaySettings() override = default;

    bool            isVisible() const;
    void            setVisible(bool value) const;
    AcCmColor       color() const;
    void            setColor(const AcCmColor& value) const;
    PyDbObjectId    layer() const;
    void            setLayer(const PyDbObjectId& value) const;
    PyDbObjectId    lineType() const;
    void            setLineType(const PyDbObjectId& value) const;
    double          lineTypeScale() const;
    void            setLineTypeScale(double value) const;
    AcDb::LineWeight lineWeight() const;
    void             setLineWeight(AcDb::LineWeight value) const;
    AcDb::PlotStyleNameType plotStyleNameType() const;
    void            setPlotStyleNameType(AcDb::PlotStyleNameType value) const;
    PyDbObjectId    plotStyleNameId() const;
    void            setPlotStyleNameId(const PyDbObjectId& value) const;

public:
    BrxCvDbStylePartDisplaySettings* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//PyBrxCvDbStyle
void makePyBrxCvDbStyleWrapper();

class PyBrxCvDbStyle : public PyBrxCvDbObject
{
    using DisplayOrientation = BrxCvDbStyle::DisplayOrientation;
    using ScalingType = BrxCvDbStyle::ScalingType;
    using OrientationRef = BrxCvDbStyle::OrientationRef;
public:
    PyBrxCvDbStyle(const PyDbObjectId& id);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbStyle(BrxCvDbStyle* ptr, bool autoDelete);
    virtual ~PyBrxCvDbStyle() override = default;

    PyBrxCvDbStylePartDisplaySettings displaySetting(DisplayOrientation orientation, const std::string& partName) const;
    boost::python::list displaySettings(BrxCvDbLabelStyle::DisplayOrientation orientation) const;
    PyDbDate            createdDate() const;
    const std::string   createdBy() const;
    PyDbDate            lastEditedDate() const;
    const std::string   lastEditedBy() const;
    void                setCreatedBy(const std::string& value) const;

    static std::string      className();
    static PyRxClass        desc();
    static PyBrxCvDbStyle   cast(const PyRxObject& src);

public:
    BrxCvDbStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleComponentWrapper
void makeBrxCvDbLabelStyleComponentWrapper();

class PyBrxCvDbLabelStyleComponent : public PyBrxCvDbSubObject
{
    using LabelAnchor = BrxCvDbLabelStyleComponent::LabelAnchor;
public:
    PyBrxCvDbLabelStyleComponent(BrxCvDbLabelStyleComponent* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleComponent() override = default;

    bool            isVisible() const;
    void            setVisible(bool isVisible) const;
    AcCmColor       color() const;
    void            setColor(const AcCmColor& value) const;
    Adesk::UInt32   anchorIndex() const;
    void            setAnchorIndex(Adesk::UInt32 index) const;
    LabelAnchor     anchorPoint() const;
    void            setAnchorPoint(LabelAnchor anchor) const;

public:
    BrxCvDbLabelStyleComponent* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbSymbolStyleWrapper
void makeBrxCvDbSymbolStyleWrapper();

class PyBrxCvDbSymbolStyle : public PyBrxCvDbStyle
{
    using OrientationRef = BrxCvDbStyle::OrientationRef;
    using SymbolType = BrxCvDbSymbolStyle::SymbolType;
    using CustomSymbol = BrxCvDbSymbolStyle::CustomSymbol;
    using ScalingType = BrxCvDbStyle::ScalingType;

public:
    PyBrxCvDbSymbolStyle();
    PyBrxCvDbSymbolStyle(bool metric);
    PyBrxCvDbSymbolStyle(const PyDbObjectId& id);
    PyBrxCvDbSymbolStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbSymbolStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);
    PyBrxCvDbSymbolStyle(BrxCvDbSymbolStyle* ptr, bool autoDelete);
    virtual ~PyBrxCvDbSymbolStyle() override = default;

    SymbolType      symbolType() const;
    void            setSymbolType(SymbolType type) const;
    CustomSymbol    customSymbol() const;
    void            setCustomSymbol(CustomSymbol symbol) const;
    bool            squareFrame() const;
    void            setSquareFrame(bool useSquareFrame) const;
    bool            circleFrame() const;
    void            setCircleFrame(bool useCircleFrame) const;
    PyDbObjectId    symbolBlockId() const;
    void            setSymbolBlockId(const PyDbObjectId& blockId) const;
    double          size() const;
    void            setSize(double size) const;
    double          rotationAngle() const;
    void            setRotationAngle(double angle) const;
    ScalingType     scalingType() const;
    void            setScalingType(ScalingType type) const;
    AcGeScale3d     fixedScale() const;
    void            setFixedScale(const AcGeScale3d& scale) const;
    OrientationRef  orientationReference() const;
    void            setOrientationReference(OrientationRef _ref) const;
    double          maximumSize() const;
    void            setMaximumSize(double size) const;
    Adesk::UInt32   asPDMODE() const;
    void            setPDMODE(Adesk::UInt32 flags) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbSymbolStyle  cast(const PyRxObject& src);

public:
    BrxCvDbSymbolStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};



//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleWrapper
void makeBrxCvDbLabelStyleWrapper();

class PyBrxCvDbLabelStyle : public PyBrxCvDbStyle
{
    using LeaderType = BrxCvDbLabelStyle::LeaderType;
    using BorderType = BrxCvDbLabelStyle::BorderType;
    using LeaderAttachment = BrxCvDbLabelStyle::LeaderAttachment;
    using DisplayMode = BrxCvDbLabelStyle::DisplayMode;
    using ForcedInsertion = BrxCvDbLabelStyle::ForcedInsertion;
    using OrientationRef = BrxCvDbStyle::OrientationRef;

public:
    PyBrxCvDbLabelStyle();
    PyBrxCvDbLabelStyle(bool metric);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode);
    PyBrxCvDbLabelStyle(const PyDbObjectId& id, AcDb::OpenMode mode, bool erased);

    PyBrxCvDbLabelStyle(BrxCvDbLabelStyle* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyle() override = default;

    PyBrxCvDbLabelStyleComponent componentAt(Adesk::UInt32 index) const;
    PyBrxCvDbLabelStyleComponent component(const std::string& name) const;
    boost::python::list components() const;
    Adesk::UInt32     componentCount() const;
    void              addComponent(const PyBrxCvDbLabelStyleComponent& pComponent) const;
    void              removeComponent_1(const PyBrxCvDbLabelStyleComponent& pComponent) const;
    void              removeComponent_2(Adesk::UInt32 index) const;
    void              moveComponent(Adesk::UInt32 fromIndex, Adesk::UInt32 toIndex) const;
    PyDbObjectId      textStyle() const;
    void              setTextStyle(const PyDbObjectId& objId) const;
    bool              isVisible() const;
    void              setVisibility(bool isVisible) const;
    PyDbObjectId      layer() const;
    void              setLayer(const PyDbObjectId& objId) const;
    OrientationRef    orientationReference() const;
    void              setOrientationReference(OrientationRef ref) const;
    ForcedInsertion   forcedInsertion() const;
    void              setForcedInsertion(ForcedInsertion value) const;
    double            readabilityBias() const;
    void              setReadabilityBias(double radAngle) const;
    bool              planReadable() const;
    void              setPlanReadable(bool isPlanReadable) const;
    bool              flipAnchorsWithText() const;
    void              setFlipAnchorsWithText(bool flipAnchors) const;
    bool              forceInsideCurve() const;
    void              setForceInsideCurve(bool forceInside) const;
    Adesk::UInt32     expressionCount() const;
    boost::python::tuple  expressionAt(Adesk::UInt32 index) const;
    void              setExpressionAt(Adesk::UInt32 index, const std::string& name, const std::string& expr, BrxCvDataType type) const;
    PyDbObjectId      draggedStateLeaderArrowHeadStyle() const;
    void              setDraggedStateLeaderArrowHeadStyle(const PyDbObjectId& objId) const;
    double            draggedStateLeaderArrowHeadSize() const;
    void              setDraggedStateLeaderArrowHeadSize(double size) const;
    Adesk::UInt32     draggedStateLeaderArrowHeadSizeExprIndex() const;
    void              setDraggedStateLeaderArrowHeadSizeExprIndex(Adesk::UInt32 index) const;
    bool              draggedStateLeaderIsVisible() const;
    void              setDraggedStateLeaderVisibility(bool isVisible) const;
    LeaderType        draggedStateLeaderType() const;
    void              setDraggedStateLeaderType(LeaderType type) const;
    AcCmColor         draggedStateLeaderColor() const;
    void              setDraggedStateLeaderColor(const AcCmColor& color) const;
    PyDbObjectId      draggedStateLeaderLinetype() const;
    void              setDraggedStateLeaderLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight  draggedStateLeaderLineweight() const;
    void              setDraggedStateLeaderLineweight(AcDb::LineWeight lineweight) const;
    LeaderAttachment  draggedStateLeaderAttachment() const;
    void              setDraggedStateLeaderAttachment(LeaderAttachment value) const;
    bool              draggedStateLeaderJustification() const;
    void              setDraggedStateLeaderJustification(bool justifyLeader) const;
    bool              draggedStateLeaderTail() const;
    void              setDraggedStateLeaderTail(bool useTail) const;
    DisplayMode       draggedStateDisplayMode() const;
    void              setDraggedStateDisplayMode(DisplayMode mode) const;
    bool              draggedStateBorderIsVisible() const;
    void              setDraggedStateBorderVisibility(bool isVisible) const;
    BorderType        draggedStateBorderType() const;
    void              setDraggedStateBorderType(BorderType type) const;
    bool              draggedStateBackgroundMask() const;
    void              setDraggedStateBackgroundMask(bool useMask) const;
    double            draggedStateBorderAndLeaderGap() const;
    void              setDraggedStateBorderAndLeaderGap(double value) const;
    Adesk::UInt32     draggedStateBorderAndLeaderGapExprIndex() const;
    void              setDraggedStateBorderAndLeaderGapExprIndex(Adesk::UInt32 index) const;
    double            draggedStateTextHeight() const;
    void              setDraggedStateTextHeight(double height) const;
    Adesk::UInt32     draggedStateTextHeightExprIndex() const;
    void              setDraggedStateTextHeightExprIndex(Adesk::UInt32 index) const;
    bool              draggedStateTagDisplayMode() const;
    void              setDraggedStateTagDisplayMode(bool displayTag) const;
    AcCmColor         draggedStateColor() const;
    void              setDraggedStateColor(const AcCmColor& color) const;
    PyDbObjectId      draggedStateLinetype() const;
    void              setDraggedStateLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight  draggedStateLineweight() const;
    void              setDraggedStateLineweight(AcDb::LineWeight lineweight) const;
    double            draggedStateMaximumTextWidth() const;
    void              setDraggedStateMaximumTextWidth(double maxWidth) const;
    Adesk::UInt32     draggedStateMaximumTextWidthExprIndex() const;
    void              setDraggedStateMaximumTextWidthExprIndex(Adesk::UInt32 index) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbLabelStyle   cast(const PyRxObject& src);

public:
    BrxCvDbLabelStyle* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleArrowWrapper
void makeBrxCvDbLabelStyleArrowWrapper();

class PyBrxCvDbLabelStyleArrow : public PyBrxCvDbLabelStyleComponent
{
public:
    PyBrxCvDbLabelStyleArrow();
    PyBrxCvDbLabelStyleArrow(BrxCvDbLabelStyleArrow* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleArrow() override = default;

    PyDbObjectId        arrowHeadStyle() const;
    void                setArrowHeadStyle(const PyDbObjectId& objId) const;
    double              arrowHeadSize() const;
    void                setArrowHeadSize(double size) const;
    Adesk::UInt32       arrowHeadSizeExprIndex() const;
    void                setArrowHeadSizeExprIndex(Adesk::UInt32 index) const;
    double              angle() const;
    void                setAngle(double radAngle) const;
    Adesk::UInt32       angleExprIndex() const;
    void                setAngleExprIndex(Adesk::UInt32 index) const;
    bool                isFixedLength() const;
    void                setFixedLength(bool isFixedLength) const;
    double              length() const;
    void                setLength(double length) const;
    Adesk::UInt32       lengthExprIndex() const;
    void                setLengthExprIndex(Adesk::UInt32 index) const;
    AcGeVector2d        offset() const;
    void                setOffset(const AcGeVector2d& offset) const;
    PyDbObjectId        linetype() const;
    void                setLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight    lineweight() const;
    void                setLineweight(AcDb::LineWeight lineweight) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbLabelStyleArrow   cast(const PyRxObject& src);

public:
    BrxCvDbLabelStyleArrow* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleBlockWrapper
void makeBrxCvDbLabelStyleBlockWrapper();

class PyBrxCvDbLabelStyleBlock : public PyBrxCvDbLabelStyleComponent
{
    using BlockAttachment = BrxCvDbLabelStyleBlock::BlockAttachment;
public:
    PyBrxCvDbLabelStyleBlock();
    PyBrxCvDbLabelStyleBlock(BrxCvDbLabelStyleBlock* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleBlock() override = default;

    PyDbObjectId        blockId() const;
    void                setBlockId(const AcDbObjectId& objId) const;
    double              height() const;
    void                setHeight(double height) const;
    Adesk::UInt32       heightExprIndex() const;
    void                setHeightExprIndex(Adesk::Int32 index) const;
    double              angle() const;
    void                setAngle(double radAngle) const;
    Adesk::UInt32       angleExprIndex() const;
    void                setAngleExprIndex(Adesk::Int32 index) const;
    BlockAttachment     attachment() const;
    void                setAttachment(BlockAttachment attachment) const;
    AcGeVector2d        offset() const;
    void                setOffset(const AcGeVector2d& offset) const;
    PyDbObjectId        linetype() const;
    void                setLinetype(const AcDbObjectId& objId) const;
    AcDb::LineWeight    lineweight() const;
    void                setLineweight(AcDb::LineWeight lineweight) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbLabelStyleBlock   cast(const PyRxObject& src);

public:
    BrxCvDbLabelStyleBlock* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleLineWrapper
void makeBrxCvDbLabelStyleLineWrapper();

class PyBrxCvDbLabelStyleLine : public PyBrxCvDbLabelStyleComponent
{
    using LengthType = BrxCvDbLabelStyleLine::LengthType;
    using LabelAnchor = BrxCvDbLabelStyleLine::LabelAnchor;
public:
    PyBrxCvDbLabelStyleLine();
    PyBrxCvDbLabelStyleLine(BrxCvDbLabelStyleLine* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleLine() override = default;

    bool                useEndPointAnchor() const;
    void                setUseEndPointAnchor(bool useEndPoint) const;
    Adesk::UInt32       endPointAnchorIndex() const;
    void                setEndPointAnchorIndex(Adesk::Int32 index) const;
    LabelAnchor         endPointAnchorPoint() const;
    void                setEndPointAnchorPoint(LabelAnchor anchor) const;
    double              angle() const;
    void                setAngle(double radAngle) const;
    Adesk::UInt32       angleExprIndex() const;
    void                setAngleExprIndex(Adesk::Int32 index) const;
    double              length() const;
    void                setLength(double length) const;
    Adesk::UInt32       lengthExprIndex() const;
    void                setLengthExprIndex(Adesk::Int32 index) const;
    AcGeVector2d        startPointOffset() const;
    void                setStartPointOffset(const AcGeVector2d& offset) const;
    AcGeVector2d        endPointOffset() const;
    void                setEndPointOffset(const AcGeVector2d& offset) const;
    LengthType          lengthType() const;
    void                setLengthType(BrxCvDbLabelStyleLine::LengthType type) const;
    double              lengthPercentage() const;
    void                setLengthPercentage(double pct) const;
    Adesk::UInt32       lengthPercentageExprIndex() const;
    void                setLengthPercentageExprIndex(Adesk::Int32 index) const;
    PyDbObjectId        linetype() const;
    void                setLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight    lineweight() const;
    void                setLineweight(AcDb::LineWeight lineweight) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbLabelStyleLine   cast(const PyRxObject& src);

public:
    BrxCvDbLabelStyleLine* impObj(const std::source_location& src = std::source_location::current()) const;
};

//-----------------------------------------------------------------------------------
//makeBrxCvDbLabelStyleTextWrapper
void makeBrxCvDbLabelStyleTextWrapper();

class PyBrxCvDbLabelStyleText : public PyBrxCvDbLabelStyleComponent
{
public:
    PyBrxCvDbLabelStyleText();
    PyBrxCvDbLabelStyleText(BrxCvDbLabelStyleText* ptr, bool autoDelete);
    virtual ~PyBrxCvDbLabelStyleText() override = default;

    std::string                   contents() const;
    void                          setContents(const std::string& contents) const;
    double                        textHeight() const;
    void                          setTextHeight(double height) const;
    Adesk::UInt32                 textHeightExprIndex() const;
    void                          setTextHeightExprIndex(Adesk::UInt32 index) const;
    double                        textAngle() const;
    void                          setTextAngle(double radAngle) const;
    Adesk::UInt32                 textAngleExprIndex() const;
    void                          setTextAngleExprIndex(Adesk::UInt32 index) const;
    AcDbMText::AttachmentPoint    textAttachment() const;
    void                          setTextAttachment(AcDbMText::AttachmentPoint attachment) const;
    AcGeVector2d                  textOffset() const;
    void                          setTextOffset(const AcGeVector2d& offset) const;
    PyDbObjectId                  textLinetype() const;
    void                          setTextLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight              textLineweight() const;
    void                          setTextLineweight(AcDb::LineWeight lineweight) const;
    double                        textMaximumWidth() const;
    void                          setTextMaximumWidth(double maxWidth) const;
    Adesk::UInt32                 textMaximumWidthExprIndex() const;
    void                          setTextMaximumWidthExprIndex(Adesk::UInt32 index) const;
    bool                          allowCurvedText() const;
    void                          setAllowCurvedText(bool allowCurved) const;
    bool                          borderIsVisible() const;
    void                          setBorderVisibility(bool isVisible) const;
    BrxCvDbLabelStyle::BorderType borderType() const;
    void                          setBorderType(BrxCvDbLabelStyle::BorderType type) const;
    bool                          borderBackgroudMask() const;
    void                          setBorderBackgroudMask(bool useMask) const;
    double                        borderGap() const;
    void                          setBorderGap(double value) const;
    Adesk::UInt32                 borderGapExprIndex() const;
    void                          setBorderGapExprIndex(Adesk::UInt32 index) const;
    AcCmColor                     borderColor() const;
    void                          setBorderColor(const AcCmColor& color) const;
    PyDbObjectId                  borderLinetype() const;
    void                          setBorderLinetype(const PyDbObjectId& objId) const;
    AcDb::LineWeight              borderLineweight() const;
    void                          setBorderLineweight(AcDb::LineWeight lineweight) const;
    AcDb::TextHorzMode            textHorizontalAlignment() const;
    void                          setTextHorizontalAlignment(AcDb::TextHorzMode alignment) const;

    static std::string           className();
    static PyRxClass             desc();
    static PyBrxCvDbLabelStyleText   cast(const PyRxObject& src);

public:
    BrxCvDbLabelStyleText* impObj(const std::source_location& src = std::source_location::current()) const;
};

#endif

#endif//BRXAPP
