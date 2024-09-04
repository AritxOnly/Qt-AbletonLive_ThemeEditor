#include "redohandler.h"

#include "themedata.h"

#include <iostream>

RedoHandler::RedoHandler() {

}

RedoHandler::~RedoHandler() {
    // RAII
    for (auto each : m_redoStack) {
        delete each;
    }
    for (auto each : m_undoStack) {
        delete each;
    }
}

void RedoHandler::pushFileSnapshot(ThemeData* fileContent) {
    ThemeData *file = new ThemeData;
    *file = *fileContent;   // deep copy
    if (m_undoStackSize >= 5) {
        ThemeData* front = m_undoStack.front();
        delete front;
        m_undoStack.pop_front();
        m_undoStackSize--;
    }
    m_undoStack.push_back(file);
    m_undoStackSize++;
    std::cout << "themeData pushed into:" << file << "\n";
    // fileContent->SaveData("fileContent.txt");
    // file->SaveData("file.txt");
}

ThemeData* RedoHandler::undo(ThemeData* current) {
    if (m_undoStackSize == 0) {
        return nullptr;
    }
    ThemeData* currentSnapshot = new ThemeData;
    *currentSnapshot = *current;    // deep copy
    ThemeData* lastSnapshot = m_undoStack.back();
    m_undoStack.pop_back();
    m_undoStackSize--;
    if (m_redoStackSize >= 5) {
        ThemeData* front = m_redoStack.front();
        delete front;
        m_redoStack.pop_front();
        m_redoStackSize--;
    }
    m_redoStack.push_back(currentSnapshot);
    m_redoStackSize++;
    return lastSnapshot;
}

ThemeData* RedoHandler::redo(ThemeData* current) {
    if (m_redoStackSize == 0) {
        return nullptr;
    }
    ThemeData* currentSnapshot = new ThemeData;
    *currentSnapshot = *current;    // deep copy
    ThemeData* lastSnapshot = m_redoStack.back();
    m_redoStack.pop_back();
    m_redoStackSize--;
    if (m_undoStackSize >= 5) {
        ThemeData* front = m_undoStack.front();
        delete front;
        m_undoStack.pop_front();
        m_undoStackSize--;
    }
    m_undoStack.push_back(currentSnapshot);
    m_undoStackSize++;
    return lastSnapshot;
}

