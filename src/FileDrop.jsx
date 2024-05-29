export default function FileDrop({ files, setFiles,canUploadFiles,singleFileOnly }) {
  function handleFiles(event) {
    if (!event.target.files) return;
    
    if (files) {
      setFiles([...files, ...event.target.files]);
    } else setFiles([...event.target.files]);
  }
  function handleSubmit(event) {
    event.preventDefault();
    alert("Form submitted");
  }
  return (
    <form onSubmit={handleSubmit}>
      <label id="file-input-label">
        Drop your files here or click this to choose files
        <input
          type="file"
          onChange={handleFiles}
          name="file-input"
          id="file-input"
          capture
          multiple={singleFileOnly}
        />
      </label>

      <button
        id="file-submit-btn"
        onClick={handleSubmit}
        disabled={!canUploadFiles}
        type="submit"
      >Upload</button>
    </form>
  );
}
