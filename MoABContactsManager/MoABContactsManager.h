//
//  MoABContactsManager.h
//  MoABContactsManagerDemo
//
//  Created by Diego Pais on 6/6/15.
//  Copyright (c) 2015 mostachoio. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>
#import "MoContact.h"

typedef NS_OPTIONS(NSUInteger, MoContactField)
{
    MoContactFieldFirstName                 = 1 << 0,
    MoContactFieldFirstNamePhonetic         = 1 << 1,
    MoContactFieldLastName                  = 1 << 2,
    MoContactFieldLastNamePhonetic          = 1 << 3,
    MoContactFieldMiddleName                = 1 << 4,
    MoContactFieldMiddleNamePhonetic        = 1 << 5,
    MoContactFieldPrefix                    = 1 << 6,
    MoContactFieldSuffixName                = 1 << 7,
    MoContactFieldPhones                    = 1 << 8,
    MoContactFieldEmails                    = 1 << 9,
    MoContactFieldNickName                  = 1 << 10,
    MoContactFieldCompany                   = 1 << 11,
    MoContactFieldJobTitle                  = 1 << 12,
    MoContactFieldDepartment                = 1 << 13,
    MoContactFieldBirthday                  = 1 << 14,
    MoContactFieldThumbnailProfilePicture   = 1 << 15,
    MoContactFieldOriginalProfilePicture    = 1 << 16,
    MoContactFieldNote                      = 1 << 17,
    MoContactFieldCreatedAt                 = 1 << 18,
    MoContactFieldUpdatedAt                 = 1 << 19,
    MoContactFieldDefaults                  =   MoContactFieldFirstName |
                                                MoContactFieldLastName |
                                                MoContactFieldPhones |
                                                MoContactFieldEmails,
    MoContactFieldAll                       = 0xFFFF,
};

@class MoABContactsManager;
@protocol MoABContactsManagerDelegate <NSObject>

- (BOOL)moABContatsManager:(MoABContactsManager *)contactsManager shouldIncludeContact:(MoContact *)contact;

@optional

- (void)addressBookDidChange;

@end

@interface MoABContactsManager : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, assign) MoContactField fieldsMask;
@property (nonatomic, strong) NSArray *sortDescriptors;

@property (weak, nonatomic) id<MoABContactsManagerDelegate> delegate;

- (void)contacts:(void(^)(ABAuthorizationStatus authorizationStatus, NSArray *contacts))contactsBlock;

- (void)addContact:(MoContact *)contact;

- (void)updateContact:(MoContact *)contact;

- (BOOL)deleteContactWithId:(NSInteger)contactId;

@end
