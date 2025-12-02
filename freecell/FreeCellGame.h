// FreeCellGame.h
// Main FreeCell game class
#pragma once

#include "types.h"
#include <cstdint>
#include <windows.h>

// Forward declarations
class CardStack;
class CardTable;
class Card;
class NodeBase;
class XmlNode;

// CardAnimationManager event listener interface
struct CardAnimation;
namespace CardAnimationManager {
    struct ICardAnimationEventListener {
        virtual void OnCardAnimationComplete(CardAnimation* anim) = 0;
    };
}

// Game state interface
struct IStateMachine {
    virtual void OnEnterState(int state) = 0;
    virtual int OnRunState(int state) = 0;
};

// Event listener interface
struct IEventListener {
    virtual void HandleEvent(Event* event) = 0;
};

// FreeCellGame class - main game logic
class FreeCellGame : public IStateMachine, 
                     public IEventListener, 
                     public CardAnimationManager::ICardAnimationEventListener {
public:
    FreeCellGame();
    virtual ~FreeCellGame() = default;
    
    // Initialization
    bool Init();
    void Cleanup();
    
    // Game flow
    void NewGame();
    void FinishGame();
    void Undo();
    
    // Game state
    bool GameDataExists();
    bool LoadGameData();
    bool SaveGameData();
    bool RemoveGameData();
    bool LoadGeneralData();
    bool SaveGeneralData();
    
    // Game logic
    void CreateHints(bool force);
    void PlayHint(Card* card1, Card* card2, CardStack* stack);
    void PlayHint(bool unused);
    void ShowHint(bool show, bool unused);
    bool Update(float deltaTime);
    void UpdateUI(bool force);
    void UpdateAccessibility();
    void UpdateMenuState();
    
    // Card interaction
    bool OnCanDragCardCheck(Card* card);
    void OnCardClicked(Card* card);
    bool OnCardDoubleClick(Card* card);
    void OnCardDragStarted(Card* card);
    void OnCardDragEnded(Card* card);
    void OnCardStackClicked(CardStack* stack);
    int OnGameLost();
    int OnGameWon();
    int OnMoveComplete();
    void OnGameStart();
    bool OnGameClose();
    
    // Interface implementations
    virtual void OnEnterState(int state) override;
    virtual int OnRunState(int state) override;
    virtual void HandleEvent(Event* event) override;
    virtual void OnCardAnimationComplete(CardAnimation* anim) override;
    
    // Settings
    void SetAnimationEnabled(bool enabled);
    void SetSoundEnabled(bool enabled);
    void SetCurrentDeckSkin(int skinId);
    void SetCurrentBackground(int bgId);
    void SetSelectedCard(Card* card, bool param1, bool param2, bool param3);
    void SetRightClickCard(Card* card);
    void SetRandomGameNumber();
    
    // Audio
    void PlaySoundW(int soundId, bool loop, unsigned int* pHandle);
    void CacheSounds();
    
    // Appearance
    void ChooseNewRandomAppearance();
    
    // Special operations
    void SpecialDealCards(int gameNumber);
    void InitialDeal(_Array<unsigned int>& cards);
    void RequestSkipAnimation();
    void SaveGameExplorerStatistics();
    
    // Static helpers
    static int GetCardIdFromFreeCellId(int id);
    static bool UpdateCardAccessName(Card* card);
    
protected:
    void doFakeClick(CardStack* stack);
    bool IsGameLost();
    unsigned int CheckForSuitCompletions(bool& found1, bool& found2);
    unsigned int checkForSuitCompletionsInStacks(_Array<CardStack*>& stacks, bool& found1, bool& found2);
    void getHintMovesInPriorityOrder(_Array<ScoredMove>& moves);
    void invalidateHints();
    void RecordCurrentGameAsLoss();
    
public:
    // Member variables (from decompilation analysis)
    // Virtual tables are handled by inheritance
    
    // State
    int m_state;
    int m_prevState;
    
    // Arrays/Lists (simplified)
    _Array<CardStack*> m_stacks;
    _Array<Card*> m_cards;
    _Array<ScoredMove> m_scoredMoves;
    
    // Game objects
    CardTable* m_cardTable;
    NodeBase* m_rootNode;
    
    // Current selection
    Card* m_selectedCard;
    Card* m_rightClickCard;
    CardStack* m_selectedStack;
    
    // Options and state flags
    unsigned int m_gameNumber;
    unsigned int m_moveCount;
    unsigned int m_someField40;
    uint64_t m_tickCount;
    
    // Boolean flags (packed in original)
    bool m_animationEnabled;
    bool m_soundEnabled;
    bool m_gameInProgress;
    bool m_gameWon;
    bool m_gameLost;
    bool m_hintsEnabled;
    bool m_hintsPending;
    bool m_undoEnabled;
};
