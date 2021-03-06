//
//  Tournament.h
//  Fifa_competitions
//
//  Created by Andy Chikalo on 11/18/16.
//  Copyright © 2016 ios.dev. All rights reserved.
//

#import <Realm/Realm.h>
#import "Player.h"
#import "Group.h"
#import "KnockoutStage.h"
#import "Utils.h"

@interface Tournament : RLMObject

@property BOOL shouldHaveGroups;
@property BOOL isInitialized;
@property NSString * id;
@property (readonly) RLMLinkingObjects *competition;

@property RLMArray<Player *><Player> * players;

// Groups stage
@property BOOL hasGroupStage;
@property BOOL has2stages;
@property RLMArray<Group*><Group> * groups;
@property BOOL isGroupStageCompleted;

// Knockout stages
@property KnockoutStage *currentStage;
@property RLMArray<KnockoutStage*><KnockoutStage> * knockoutStages;
@property BOOL isCompleted;

@property Player * winner;
@property RLMArray<Player*><Player>* groupWinners;

- (BOOL) canCreateGroups;

- (instancetype)initWithPlayers:(RLMArray<Player *><Player> *)players;

- (int) currentWeek;

/// Generates group stage if [self canCreateGroup] == true
///
/// Returns array of groups
- (RLMArray<Group*><Group> *) generateGroups;

/// Updates statisstics if group stage exists;
/// ! Updates data base
/// Should be used after teournament is saved to db
- (void) updateStatistics;

/// Generate initial knockout stage if `self.currentStage == nil`
/// or group stage is completed
///
/// Returns current knockout stage or nil on error
- (KnockoutStage *) generateInitialKnockoutStage;

/// Generate next knockout stage if `self.currentStage.isCompleted`
/// ! Updates data base
/// Should be used after teournament is saved to db
///
/// Returns current knockout stage or nil on error
- (KnockoutStage *) generateNextKnockoutStage;

- (RLMArray<Player *><Player> *) getGroupsWinners;
- (void) generateKnockoutStagesFromGroups;
@end
