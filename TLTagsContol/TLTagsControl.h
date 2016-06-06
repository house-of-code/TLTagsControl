//
//  TLTagsControl.h
//  TagsInputSample
//
//  Created by Антон Кузнецов on 11.02.15.
//  Copyright (c) 2015 TheLightPrjg. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TLTagsControl;

@protocol TLTagsControlDelegate <NSObject>

- (void)tagsControl:(TLTagsControl *)tagsControl tappedAtIndex:(NSInteger)index;
- (void)tagsControl:(TLTagsControl *)tagsControl textDidChange:(NSString *)newText;
- (void)tagsControl:(TLTagsControl *)tagsControl deleteTappedForTag:(NSObject *)tag;

- (NSString *)tagsControl:(TLTagsControl *)tagsConrol titleForTag:(NSObject *)item;

@end

@protocol TLTagsControlDataSource <NSObject>

//- (NSString *)tagsControl:(TLTagsControl *)tagsControl titleForTag: (

@end

typedef NS_ENUM(NSUInteger, TLTagsControlMode) {
    TLTagsControlModeEdit,
    TLTagsControlModeList,
};

@interface TLTagsControl : UIScrollView

@property (nonatomic, strong) NSMutableArray *tags;
@property (nonatomic, strong) UIColor *tagsBackgroundColor;
@property (nonatomic, strong) UIColor *tagsTextColor;
@property (nonatomic, strong) UIColor *tagsDeleteButtonColor;
@property (nonatomic, strong) NSString *tagPlaceholder;
@property (nonatomic) TLTagsControlMode mode;
@property (nonatomic, assign) UIKeyboardType keyboardType;
@property (assign, nonatomic) id<TLTagsControlDelegate> tapDelegate;

- (id)initWithFrame:(CGRect)frame andTags:(NSArray *)tags withTagsControlMode:(TLTagsControlMode)mode delegate:(NSObject<TLTagsControlDelegate> *)delegate;

- (void)addTag:(NSObject *)tag;
- (void)removeTag:(NSObject *)tag;
//- (void)removeTagAtIndex:(NSInteger)index;
- (void)reloadTagSubviews;

@end