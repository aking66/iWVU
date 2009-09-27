//
//  BuildingList.h
//  iWVU
//
//  Created by Jared Crawford on 6/13/09.
//  Copyright 2009 Jared Crawford. All rights reserved.
//

/*
 Copyright (c) 2009 Jared Crawford
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 
 The trademarks owned or managed by the West Virginia 
 University Board of Governors (WVU) are used under agreement 
 between the above copyright holder(s) and WVU. The West 
 Virginia University Board of Governors maintains ownership of all 
 trademarks. Reuse of this software or software source code, in any 
 form, must remove all references to any trademark owned or 
 managed by West Virginia University.
 */ 

#import <UIKit/UIKit.h>


typedef enum {
	BuildingSelectionStyleCheckMark,
	BuildingSelectionStyleReturn
} BuildingSelectionStyle;
	

@protocol BuildingListDelegate;


@interface BuildingList : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate> {
	
	id<BuildingListDelegate> delegate;
	
	NSArray *downtownBuildings;
	NSArray *HSCBuildings;
	NSArray *evansdaleBuildings;
	NSArray *allBuildings;
	NSArray *searchResultsBuildings;
	
	IBOutlet UITableView *theTableView;
	IBOutlet UISearchBar *theSearchBar;
	
	BOOL allowsCurrentLocation;
	BOOL allowsAllBuildings;
	BuildingSelectionStyle style;
	
}

@property(nonatomic, assign) id delegate;
@property(nonatomic) BOOL allowsCurrentLocation;
@property(nonatomic) BOOL allowsAllBuildings;
@property(nonatomic) BuildingSelectionStyle style;

@end



@protocol BuildingListDelegate
-(void)BuildingList:(BuildingList *)aBuildingList didFinishPickingBuilding:(NSString *)aBuilding;
@end

