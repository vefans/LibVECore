//
//  VECoreYYModel.h
//  VECoreYYModel <https://github.com/ibireme/VECoreYYModel>
//
//  Created by ibireme on 15/5/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#if __has_include(<VECoreYYModel/VECoreYYModel.h>)
FOUNDATION_EXPORT double VECoreYYModelVersionNumber;
FOUNDATION_EXPORT const unsigned char VECoreYYModelVersionString[];
#import <VECoreYYModel/NSObject+VECoreYYModel.h>
#import <VECoreYYModel/VECoreYYClassInfo.h>
#else
#import "NSObject+VECoreYYModel.h"
#import "VECoreYYClassInfo.h"
#endif
