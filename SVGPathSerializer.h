//
//  SVGPathSerializer.h
//
//  Copyright (c) 2013 Ponderwell, Fjölnir Ásgeirsson, Ariel Elkin, and Contributors
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/*!
 *  Returns an array of CGPathRefs contained within the passed SVG string.
 *
 *  @param svgString The string containing the SVG formatted path.
 *  @param attributes An optional pointer for storing a map table containing SVG attributes for the paths
 *
 *  @return An array of CGPathRef objects or nil if none are found
 */
NSArray *CGPathsFromSVGString(NSString *svgString, NSMapTable **attributes);


/*!
 *  Returns SVG representing `paths`
 *
 *  @param paths An array of CGPathRefs to construct the SVG from
 *  @param attributes An optional map table of SVG attributes for the paths
 *
 *  @return SVG representing `paths`
 */
NSString *SVGStringFromCGPaths(NSArray *paths, NSMapTable *attributes);

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>

@interface UIBezierPath (SVGPathSerializer)
+ (NSArray *)pathsFromContentsOfSVGFile:(NSString *)aPath;
+ (NSArray *)pathsFromSVGString:(NSString *)svgString;
- (NSString *)SVGRepresentation;
@end
#endif