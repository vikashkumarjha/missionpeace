package core

import (
	"errors"
	"fmt"
	"math/rand"
	"os"
)

type Cell struct {
	R rune
	C rune
}

type TicToe struct {
	_board *[3][3]rune
}

func New() *TicToe {
	t := TicToe{}
	t._board = new([3][3]rune)
	for i, row := range t._board {
		for j, _ := range row {
			t._board[i][j] = '#'
		}
	}
	return &t
}

func (t *TicToe) DumpBoard() {
	fmt.Printf("\n")
	for _, row := range t._board {
		fmt.Printf("\n")
		for _, v := range row {
			fmt.Printf("%v \t", string(v))
		}
	}
}

func (t *TicToe) FindPlayerSymbol(turn int) rune {
	if turn%2 == 0 {
		return 'X'
	}
	return 'O'
}

func (t *TicToe) FindUnassignedCell() (Cell, bool, error) {
	var emptyCell []Cell
	for rowId, row := range t._board {
		for colId, v := range row {
			if v == '#' {
				emptyCell = append(emptyCell,
					Cell{rune(rowId), rune(colId)})
			}
		}
	}

	if len(emptyCell) == 0 {
		return Cell{}, false, errors.New("no cell")
	}

	cellIndex := rand.Intn(len(emptyCell))
	return emptyCell[cellIndex], true, nil
}
func (t *TicToe) Play(player rune, cell Cell) {
	ok, winner := t.FindWinner()
	if ok {
		fmt.Printf("\n winner is (%v) ", string(winner))
		t.DumpBoard()
		os.Exit(0)
	}
	t._board[cell.R][cell.C] = player
}

func (t *TicToe) FindWinner() (bool, rune) {
	// X is pos
	var rowCount [3]int
	var colCount [3]int
	diag := 0
	antiDiag := 0
	for rowId, row := range t._board {
		for colId, v := range row {
			if v == 'X' {
				rowCount[rowId]++
				colCount[colId]++
				if rowId == colId {
					diag++
				}
				if rowId == 3-colId-1 {
					antiDiag++
				}
			}
			if v == 'O' {
				rowCount[rowId]--
				colCount[colId]--
				if rowId == colId {
					diag--
				}
				if rowId == 3-colId-1 {
					antiDiag--
				}
			}

		}
	}

	if rowCount[0] == 3 || rowCount[1] == 3 || rowCount[2] == 3 || diag == 3 || antiDiag == 3 {
		return true, 'X'
	}

	if colCount[0] == 3 || colCount[1] == 3 || colCount[2] == 3 || diag == 3 || antiDiag == 3 {
		return true, 'X'
	}
	if rowCount[0] == -3 || rowCount[1] == -3 || rowCount[2] == -3 || diag == -3 || antiDiag == -3 {
		return true, 'O'
	}

	if colCount[0] == -3 || colCount[1] == -3 || colCount[2] == -3 || diag == -3 || antiDiag == -3 {
		return true, 'O'
	}
	return false, '#'
}
