//
//  League.h
//  Fifa_competitions
//
//  Created by Andy Chikalo on 11/18/16.
//  Copyright © 2016 ios.dev. All rights reserved.
//

#import <Realm/Realm.h>
#import "Player.h"
#import "Week.h"
@class Statistics;

@interface League : RLMObject

@property  NSString * id;
@property BOOL twoStages;
@property RLMArray<Player *><Player> * players;
@property RLMArray<Week *><Week> * weeks;
@property Statistics * statistics;
@property BOOL isCompleted;
@property int currentWeek;
@property (readonly) RLMLinkingObjects *competition;

+ (NSArray<Week *> *) generateScheduleFrom:(NSArray<Player *> *) _players hasTwoStages:(BOOL) twoStages;
+ (NSArray<Player *> *) convertPlayersToNSArray: (RLMArray<Player *><Player> *) players;

+ (Week *) generateFirstWeekWithTop: (NSArray<Player *> *) top bottom: (NSArray<Player *> *) bottom;
- (NSError *) generateMatches;
- (void) updateStatistics;

@end
