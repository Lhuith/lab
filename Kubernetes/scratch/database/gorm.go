package Database

import (
	"fmt"
	"os"

	"github.com/gofrs/uuid"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Gorm_Server struct {
	db *gorm.DB
}

func (gs *Gorm_Server) Ping() int {
	if db, error := gs.db.DB(); error != nil {
		return 500
	} else {
		if db.Ping() == nil {
			return 200
		} else {
			return 500
		}
	}
}

var (
	RoachUrl = func(url string) string {
		return "postgresql://root@" + url + ":26257/defaultdb?sslmode=disable"
	}
	Server = Gorm_Server{}
)

type Account struct {
	ID uuid.UUID `gorm:"type:uuid;default:uuid_generate_v4()"`
}

func GormPing() int {
	return Server.Ping()
}

func Gormn() {
	fmt.Println("Hey I'm gormin ova here")
}

func init() {
	fmt.Println("GORRRRRRRRRMMMMMMMMMMMM")
	fmt.Println(os.Getenv("DATABASE_URL"))

	db, err := gorm.Open(postgres.Open(RoachUrl(os.Getenv("DATABASE_URL"))))
	Server.db = db

	if err != nil {
		panic(fmt.Sprintf("failed to connect to database: %v", err))
	}

}
