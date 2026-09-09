{{- define "templating-deep-dive.fullname" -}}
{{- $defaultName := printf "%s-%s" .Release.Name .Chart.Name }}
{{- .Values.customName | default $defaultName | trunc 63 | trimSuffix "-" -}}
{{- end -}}
{{- define "templating-deep-dive.selector.labels" -}}
app: {{ .Chart.Name }}
release: {{ .Release.Name }}
{{- end -}}


{{/* expects a int or string to be passed as context*/}}
{{- define "templating-deep-dive.validators.portRanges" -}}
{{- $sanatizedPort := int . -}}

{{/* port validation */}}
{{- if or (lt $sanatizedPort 1) (gt $sanatizedPort 65535) -}}
{{- fail "port range must be 1-65535" -}}
{{- end -}}
{{- end -}}


{{/* expects a port and type to be passed as context*/}}
{{- define "templating-deep-dive.validators.service" -}}
{{- include  "templating-deep-dive.validators.portRanges" .port -}}

{{/* type validation */}}
{{- $allowedSVC := list "ClusterIP" "NodePort" }}
{{- if not (has .type $allowedSVC) -}}
{{- fail (printf "invalid service type %s" .type) -}}
{{- end -}}

{{- end -}}
