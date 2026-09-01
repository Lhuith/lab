package meta

type (
	Meta struct {
		Service   string
		Operation string
		Values    map[string]string
	}
	GeneratedEntry struct {
		File     string
		Line     int
		Function string
		Meta     Meta
	}
	GeneratedFileEntry struct {
		File string
		Meta Meta
	}
)

func (m Meta) Empty() bool {
	return m.Service == "" && m.Operation == "" && len(m.Values) == 0
}
