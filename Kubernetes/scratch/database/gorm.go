package Database

import (
	"fmt"
	"log"
	"os"

	"github.com/gofrs/uuid"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

type Account struct {
	ID uuid.UUID `gorm:"type:uuid;default:uuid_generate_v4()"`
}

func Gormn() {
	fmt.Println("Hey I'm gormin ova here")
}

func init() {
	fmt.Println("GORRRRRRRRRMMMMMMMMMMMM")
	_, err := gorm.Open(postgres.Open(os.Getenv("DATABASE_URL")+"&application_name=$ docs_simplecrud_gorm"), &gorm.Config{})
	if err != nil {
		log.Fatal(err)
	}

}
