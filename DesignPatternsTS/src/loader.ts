import * as fs from 'fs';

export interface RecordHandler<T> {
  addRecord(record: T): void;
}

export function loader<T>(
  filename: string,
  RecordHandler: RecordHandler<T>
): void {
  const data: T[] = JSON.parse(fs.readFileSync(filename).toString());
  data.forEach((record) => RecordHandler.addRecord(record));
}