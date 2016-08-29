/*
 * This file is part of the PocketSVG package.
 * Copyright (c) Ponderwell, Ariel Elkin, Fjölnir Ásgeirsson, and Contributors
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */


#import "SVGPortability.h"

NS_ASSUME_NONNULL_BEGIN

/// A view that parses, renders, and display an SVG file.

IB_DESIGNABLE
@interface SVGImageView : PSVGView


/*!
 *  @discussion Initialises a view that parses, renders and displays the provided SVG.
 *
 *  @param aSVGName The name of an SVG file in the app bundle.
 *
 *  @return An `UIView` or `NSView` displaying the SVG.
 * 
 *  @code let svgImageView = SVGImageView(SVGNamed: "svg_file_name")
 svgImageView.contentMode = .ScaleAspectFit
 view.addSubview(svgImageView)
 */
+ (instancetype)imageViewWithSVGNamed:(NSString *)aSVGName;


/*!
 *  @discussion Renders a new SVG given a file name.
 *
 *  @param svgName The name of an SVG file in the app bundle.
 *
 *  @code svgImageView.svgName = "svg_file_name"
 */
@property(nonatomic, copy) IBInspectable NSString *svgName;


/*!
 *  @discussion Renders a new SVG given the XML string of the SVG.
 *
 *  @param svgSource The XML string of an SVG.
 *
 *  @code let svgImageView = SVGImageView()
 let svgURL = NSBundle.mainBundle().URLForResource("svg_file_name", withExtension: "svg")!
 let svgSource = try! String(contentsOfURL: svgURL)
 svgImageView.svgSource = svgSource
 view.addSubview(svgImageView)
 */
@property(nonatomic, copy) NSString *svgSource;


/*!
 *  @discussion Solidly fills the shape formed by the SVG path with the given color.
 *
 *  @param fillColor A color to fill the SVG shape with.
 *
 */
@property(nonatomic, copy) IBInspectable PSVGColor *fillColor;


/*!
 *  @discussion Solidly colors the path generated by the SVG file.
 *
 *  @param strokeColor A color to color the path with.
 *
 */
@property(nonatomic, copy) IBInspectable PSVGColor *strokeColor;


/*!
 *  @discussion Specifies whether or not line thickness should be scaled 
 when scaling paths.
 *
 */
@property(nonatomic) IBInspectable BOOL scaleLineWidth;

NS_ASSUME_NONNULL_END

@end
